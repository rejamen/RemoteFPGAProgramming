#ifndef SERVER_H
#define SERVER_H


#include <QWidget>
#include <QProgressBar>
#include <QTcpSocket>
#include <QTcpServer>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>

#include <QProcess>

namespace Ui {
class server;
}

class server : public QWidget
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = 0);
    ~server();

private:
    Ui::server *ui;

public:
    QPushButton *startBtn;
    QPushButton *programBtn;
    QProgressBar *progressBar;
    QGridLayout *layout;

    int server_status;
    QTcpServer *tcpServer;
    
    
    
    QTcpSocket *tcpServerConnection;

    QString fileName;
    QString fileSize;
    bool isInfoGot;
    QString storagePath;

    QString command;
    QProcess *process;

    QStringList messages;

public slots:
    void on_starting_clicked();
    void acceptConnection();
    void slotReadClient();

    void runCommand();
    void programDevice();

};

#endif // SERVER_H
