#ifndef RASPCAMMW_H
#define RASPCAMMW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QLineEdit>
#include "videoview.h"
#include "tcprequest.h"
#include "netscaner.h"
#include "controlclient.h"

namespace Ui {
class RaspCamMW;
}

class RaspCamMW : public QMainWindow
{
    Q_OBJECT

public:
    explicit RaspCamMW(QWidget *parent = 0);
    ~RaspCamMW();

private slots:
    void on_btnScan_clicked();
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_btnRecord_clicked();
    void recvmsg(QString msg);
    void recvvcmds(QMap<QString, QString> params);
    void recvcmdstr(QString cmd);
    void laterstart();
    void drawprocess();
    void on_btn_confirm_clicked();
    void on_btn_remoteRcd_clicked();
    void on_btn_getrecord_clicked();
    void on_btnSnap_clicked();

    //porgramcion KIT
    void fileOpened();
    void connectToServer();
    void onSend();

    void displayError(QAbstractSocket::SocketError socketError);

     void slotReadClient();



private:
    void _extUISetUp();
    void _exDataSetUp();
    QString _getlecontant(QLineEdit *clts, QString orgkey);
    QString _collectcmd();
    VideoView *_vview;
    Ui::RaspCamMW *ui;
    QString _streamurl;
    NetScaner *scan;
    ControlClient *ctlc;
    QTimer _processtimer;
    QTime _processtime;
    QHostAddress _saddr;
    quint16 _ctlport;
    quint16 _vodport;
    int _cntdown_msec;
    QMap<QString, QString> orgval;
    QString fileName;

    QTcpSocket *tcpSocket;
    bool error;
    quint16 blockSize;
};

#endif // RASPCAMMW_H
