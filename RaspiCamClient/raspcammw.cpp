#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include "tcprequest.h"
#include "ui_raspcammw.h"
#include "raspcammw.h"
#include "dlgrecord.h"


//**********************************************************************
RaspCamMW::RaspCamMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RaspCamMW)
{
    ui->setupUi(this);
    _exDataSetUp();
    _extUISetUp();
}
//**********************************************************************
RaspCamMW::~RaspCamMW()
{
    if(_vview != NULL) {
        if(_vview->isStart()) {
            _vview->stop();
        }
        delete _vview;
    }
    if(ctlc != NULL) {
        delete ctlc;
    }
    if(scan != NULL) {
        delete scan;
    }
    delete ui;
}
//**********************************************************************
void RaspCamMW::_extUISetUp() {
    _vview = new VideoView(ui->videow);
    QSize vsize(ui->videow->size());
    _vview->setSize(vsize);
    ui->btnRecord->setEnabled(false);
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnSnap->setEnabled(false);

    QPixmap playPixmap(":pics/play.png");
    QIcon playIcon(playPixmap);
    ui->btnStart->setIcon(playIcon);

    QPixmap stopPixmap(":pics/stop.png");
    QIcon stopIcon(stopPixmap);
    ui->btnStop->setIcon(stopIcon);

    QPixmap snapPixmap(":pics/snapshot.png");
    QIcon snapIcon(snapPixmap);
    ui->btnSnap->setIcon(snapIcon);

    QPixmap recordPixmap(":pics/record.png");
    QIcon recordIcon(recordPixmap);
    ui->btnRecord->setIcon(recordIcon);

    QPixmap searchPixmap(":pics/video.png");
    QIcon searchIcon(searchPixmap);
    ui->btnScan->setIcon(searchIcon);

    QPixmap programPixmap(":pics/program.png");
    QIcon programIcon(programPixmap);
    ui->btnProgram->setIcon(programIcon);
    ui->btnProgram->setEnabled(false);

    QPixmap folderPixmap(":pics/folder.png");
    QIcon folderIcon(folderPixmap);
    ui->btnBitFile->setIcon(folderIcon);
    ui->btnBitFile->setEnabled(false);

    QPixmap conectPixmap(":pics/conect.png");
    QIcon conectIcon(conectPixmap);
    ui->btnConect->setIcon(conectIcon);

    ui->lbl_address->setVisible(false);
    ui->lblprocess->setVisible(false);

    ui->tab_2->setEnabled(false);

    ui->tab->setFocus();

    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
}
//**********************************************************************
void RaspCamMW::_exDataSetUp() {
    _streamurl = "";
    ctlc = NULL;
    scan = new NetScaner();
    connect(scan, SIGNAL(routeOut(QString)), this, SLOT(recvmsg(QString)));
    _processtimer.setInterval(1000);
    connect(&_processtimer, SIGNAL(timeout()), this, SLOT(drawprocess()));
    _cntdown_msec = 5000;
    _ctlport = 9999;
    _vodport = 0;

    error = false;

    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));


    connect(ui->btnBitFile, SIGNAL(clicked(bool)), this, SLOT(fileOpened()));
    connect(ui->btnConect, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(ui->btnProgram, SIGNAL(clicked(bool)), this, SLOT(onSend()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
}
//**********************************************************************
QString RaspCamMW::_getlecontant(QLineEdit *clts, QString orgkey) {
    if(clts == NULL) {
        return "";
    }
    bool ok = false;
    int val = clts->text().toInt(&ok);
    if(!ok) {
        if(orgval.contains(orgkey)) {
            val = orgval[orgkey].toInt(); //here should be success
        } else {
            val = 0;
        }
    }
    return QString::number(val);
}
//**********************************************************************
QString RaspCamMW::_collectcmd() {
    QString _base = "brightness=50";
    //_base += _getlecontant(ui->le_bright, "brightness");
    _base += ",";

    _base += "bitrate=4500000";
    //_base += _getlecontant(ui->le_BitRate, "bitrate");
    _base += ",";

    _base += "width=1024";
    //_base += _getlecontant(ui->le_width, "width");
    _base += ",";

    _base += "height=768";
    //_base += _getlecontant(ui->le_height, "height");
    _base += ",";


    _base += "fps=30";
    //_base += _getlecontant(ui->le_fps, "fps");
    _base += ",";
    return _base;
}
//**********************************************************************
void RaspCamMW::on_btnScan_clicked() {
    scan->start();

}
//**********************************************************************
void RaspCamMW::on_btnStart_clicked() {
    if(!_vview->isStart()) {
        if(ctlc != NULL) {
            ctlc->start();
            _vview->setWeburl(_streamurl);
            _processtimer.start();
            _processtime.restart();
            QTimer::singleShot(_cntdown_msec, this, SLOT(laterstart()));
        }
    }
}
//**********************************************************************
void RaspCamMW::on_btnStop_clicked() {
    if(_vview->isStart()) {
        if(ctlc != NULL) {
            ctlc->stop();
        }
        _vview->stop();
    }
}
//**********************************************************************
void RaspCamMW::on_btnRecord_clicked() {
    if(!_vview->isStart()) {
        return;
    }
    if(!_vview->isRecording()) {
        _vview->startRecording("./recordfile.mp4");
        ui->btnRecord->setText("Stop REC");
    } else {
        _vview->stopRecording();
        ui->btnRecord->setText("Record");
    }
}
//**********************************************************************
void RaspCamMW::recvmsg(QString msg) {
    _streamurl.clear();
    _streamurl = "rtsp://";
    _streamurl = _streamurl + msg + "/";
    ui->lbl_address->setText("address: " + _streamurl);
    ui->btnRecord->setEnabled(true);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(true);

    ui->btnSnap->setEnabled(true);




    //verify in netscaner so no need to verify here
    QStringList _tmplist = msg.split(":");
    _saddr = QHostAddress(_tmplist.at(0));
    if(!_saddr.isNull()) {
        if (ctlc != NULL) {
            delete ctlc;
            ctlc = NULL;
        }
        ctlc = new ControlClient(_saddr, 9999); //ctl port
        connect(ctlc, SIGNAL(routeOut(QMap<QString,QString>)),
                this, SLOT(recvvcmds(QMap<QString,QString>)));
        connect(ctlc, SIGNAL(routeOut(QString)),
                this, SLOT(recvcmdstr(QString)));
        if(ctlc != NULL) {
            ctlc->get_vodport();
            ctlc->get_currparams();
        }

        QMessageBox::information(this, tr("Cliente"),
                             "Se ha establecido la conexión con el servidor " + _saddr.toString()
                                );

        ui->tab_2->setEnabled(true);


    }
    else{
        QMessageBox::information(this, tr("Cliente"),
                             tr("Error al establecer conexión. Asegúrese de que la aplicación Servidor se está ejecutando."
                                ));
    }

}
//**********************************************************************
void RaspCamMW::recvvcmds(QMap<QString, QString> params) {
    if(params.size() > 0) {

        orgval = params;
        /*if(params.contains("width")) {
            ui->le_width->setText(params["width"]);
        }
        if(params.contains("height")) {
            ui->le_height->setText(params["height"]);
        }
        if(params.contains("bitrate")) {
            ui->le_BitRate->setText(params["bitrate"]);
        }
        if(params.contains("brightness")) {
            ui->le_bright->setText(params["brightness"]);
        }
        if(params.contains("fps")) {
            ui->le_fps->setText(params["fps"]);
        }*/
    }
}
//**********************************************************************
void RaspCamMW::recvcmdstr(QString cmd) {
    QStringList cmdlist = cmd.split("|");
    if(cmdlist.length() != 2) {
        return;
    }
    if(QString::compare(cmdlist[0], "vodport", Qt::CaseInsensitive) == 0) {
        _vodport = cmdlist[1].toInt();
        disconnect(ctlc, SIGNAL(routeOut(QString)),
                   this, SLOT(recvcmdstr(QString)));
    }
}
//**********************************************************************
void RaspCamMW::laterstart() {

    if(_vview != NULL) {
        if(!_vview->isStart()) {
            _vview->start();
        }
    }
}
//**********************************************************************
void RaspCamMW::drawprocess() {
    ui->progressBar->setVisible(true);
    if(_processtime.elapsed() < _cntdown_msec) {
        QString full;
        int getbit = _processtime.elapsed() / 1000;
        for(int i = 0; i < _cntdown_msec / 1000; i++) {
            if(i <= getbit) {
                full.push_back("*");

            } else {
                full.push_back("-");

            }
            ui->progressBar->setValue(ui->progressBar->value() + 4);
        }
        ui->lblprocess->setText(full);
    } else {
        ui->lblprocess->setText("");
        _processtimer.stop();
        ui->progressBar->setValue(100);
        ui->progressBar->setVisible(false);
        ui->progressBar->setValue(0);
    }
}
//**********************************************************************
void RaspCamMW::on_btn_confirm_clicked() {
    if(ctlc != NULL) {
        ctlc->change(_collectcmd());
    }
    if(_vview->isStart()) {
        _vview->stop();
    }
    _vview->setWeburl(_streamurl);
    _processtimer.start();
    _processtime.restart();
    QTimer::singleShot(_cntdown_msec, this, SLOT(laterstart()));
}
//**********************************************************************
void RaspCamMW::on_btn_remoteRcd_clicked() {
    if(_vview->isStart()) {
        _vview->stop();
    }
    if(ctlc != NULL) {
        ctlc->record();
        _vview->setWeburl(_streamurl);
        _processtimer.start();
        _processtime.restart();
        QTimer::singleShot(_cntdown_msec, this, SLOT(laterstart()));
    }
}
//**********************************************************************
void RaspCamMW::on_btn_getrecord_clicked() {
    DlgRecord *dlg = new DlgRecord(this);
    if (!_saddr.isNull()) {
        dlg->setData(_saddr, _ctlport, _vodport);
        dlg->exec();
    }
    delete dlg;
}
//**********************************************************************
void RaspCamMW::on_btnSnap_clicked() {
    if(_vview->isStart()) {
        if(!QDir::current().entryList(QDir::Dirs).contains("snapshots")) {
            QDir current = QDir::current();
            if(!current.mkdir(QDir::currentPath() + QString("/snapshots"))) {
                return;
            }
        }
        QString sname = "./snapshots/snapshot_";
        sname.append(QDateTime::currentDateTime().toString("yyyy_MM_dd-hh:mm:ss"));
        sname.append(".png");    //default to png
        _vview->snapshot(sname);
    }
}
//**********************************************************************
void RaspCamMW::fileOpened()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open file"));
    QFileInfo fileInfo(fileName);
    //fileLabel->setText(fileInfo.fileName() + " : " + QString::number(fileInfo.size()));
    //qDebug() << fileName;
    ui->btnProgram->setEnabled(true);
}
//**********************************************************************
void RaspCamMW::connectToServer()
{
    QString address = _saddr.toString();
    int port = 33333;

    tcpSocket->connectToHost(address, port);

    if(!error)
    {
        QMessageBox::information(this, tr("Cliente"),
                             tr("Conexión establecida con éxito. Puede seleccionar el .bit para programar el Kit."
                                ));
        ui->btnBitFile->setEnabled(true);
        error = false;
    }
}
//*********************************************************************
void RaspCamMW::onSend()
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray q = file.readAll();
    tcpSocket->write(q);
 }
//*********************************************************************
void RaspCamMW::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Cliente"),
                                 tr("Servidor no encontrado. Verifique que la "
                                    "dirección IP y el puerto seleccionados sean correctos."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Cliente"),
                                 tr("Conexión rechazada."
                                    "Asegúrese de que la aplicación Servidor se está ejecutando, "
                                    "y verifique además la dirección IP y el puerto seleccionados."
                                    ));
        break;
    default:
        QMessageBox::information(this, tr("Cliente"),
                                 tr("Ha ocurrido el siguiente error: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    error = true;
}
//*********************************************************************
//*********************************************************************
void RaspCamMW::slotReadClient()
{
    QByteArray msgFromServer = tcpSocket->readAll();
    qDebug() << msgFromServer;

    if (msgFromServer == "OKOK")
    {
        QMessageBox::information(this, tr("Cliente"),
                             "Se ha programado el kit satisfactoriamente."
                                );
        ui->btnBitFile->setEnabled(false);
        ui->btnProgram->setEnabled(false);
        tcpSocket->close();
    }
    else
    {
        QMessageBox::information(this, tr("Cliente"),
                             "Ha ocurrido un error al programar el kit."
                                );
    }
}
