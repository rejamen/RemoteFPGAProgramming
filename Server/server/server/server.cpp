#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::server)
{
        ui->setupUi(this);

        startBtn = new QPushButton(this);
        startBtn->setText("Connect");



        layout = new QGridLayout;
        layout->addWidget(startBtn, 0, 0);


        process = new QProcess(this);

        setWindowTitle("Programacion remota Nexys2");


        connect(startBtn, SIGNAL(clicked()), this, SLOT(on_starting_clicked()));


        setLayout(layout);

        storagePath = "/home/pi/projects/server/recibidos";


        emit on_starting_clicked();

}
//*****************************************************************
server::~server()
{
    delete ui;
    server_status=0;
}
//*****************************************************************
void server::on_starting_clicked()
{
    startBtn->setText("Connecting...");
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    if (!tcpServer->listen(QHostAddress::Any, 33333) && server_status==0)
    {
        qDebug() <<  QObject::tr("Error al iniciar el servidor: %1.").arg(tcpServer->errorString());
    }
    else
    {
        server_status=1;
        startBtn->setText("Listo!!!");
    }
}
//*****************************************************************
void server::acceptConnection()
{

    tcpServerConnection = tcpServer->nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),this, SLOT(slotReadClient()));

    QDir::setCurrent(storagePath);

}
//*****************************************************************
void server::slotReadClient()
{

    QByteArray line = tcpServerConnection->readAll();

    QFile target;
    fileName = storagePath + "/copied.bit";
    target.setFileName(fileName);


    if (!target.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "No se pudo abrir el fichero.";
        return;
    }
    target.write(line);

    target.close();

    qDebug() << "file size: " << target.size();

    qDebug() << "Finished!";

    emit programDevice();



}
//*****************************************************************
void server::runCommand()
{
    process->start(command);
    if(!process->waitForFinished())
           qDebug() << "error";

}
//*****************************************************************
void server::programDevice()
{
    command = "djtgcfg prog -d DOnbUsb -i 0 -f " + fileName;
    emit runCommand();
}
//*****************************************************************
