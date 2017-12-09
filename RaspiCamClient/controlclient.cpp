#include "controlclient.h"

ControlClient::ControlClient(QHostAddress server, quint16 port, QObject *parent) :
    QObject(parent),
    _serveraddr(server),
    _port(port)
{
    // here not really keepalive because ctlserver just close socket
    _request = new TcpRequest(this, 1);
    connect(_request, SIGNAL(sigmsg(QString)), this, SLOT(servermsg(QString)));
    _raspcmd_prefix = "raspivid";
    _supportcmds << "start" << "stop" << "change" << "record" << "get_records"
                 << "rm_records" << "get_vodport" << "get_currparams";
    _dftwaitmsec = 100;
}

ControlClient::~ControlClient() {
    if(_request != NULL) {
        delete _request;
        _request = NULL;
    }
}

void ControlClient::_sig_cmd(const QString &cmd) {
    if(_supportcmds.contains(cmd)) {
        if(_request->connectHost(_serveraddr, _port, _dftwaitmsec)) {
            _request->sendData(cmd.toStdString().c_str());
        }
    }
}

void ControlClient::_para_cmd(const QString &prefix, const QString &params) {
    if(_supportcmds.contains(prefix)) {
        QString cmd = "";
        cmd = prefix + "|";
        cmd += params;
        if(_request->connectHost(_serveraddr, _port, _dftwaitmsec)) {
            _request->sendData(cmd.toStdString().c_str());
        }
    }
}

void ControlClient::start() {
    _sig_cmd("start");
}

void ControlClient::stop() {
    _sig_cmd("stop");
}
void ControlClient::change(QString params) {
    _para_cmd("change", params);
}

void ControlClient::record() {
    _sig_cmd("record");
}

void ControlClient::get_records()
{
    _sig_cmd("get_records");
}

void ControlClient::get_vodport() {
    _sig_cmd("get_vodport");
}

void ControlClient::get_currparams() {
    _sig_cmd("get_currparams");
}

void ControlClient::rm_records(QString params) {
    _para_cmd("rm_records", params);
}

void ControlClient::servermsg(QString msg) {
    qDebug() << Q_FUNC_INFO << msg;
    QStringList cmds = msg.split("|");
    if(cmds.length() == 2) {
        if(cmds[0].compare("records", Qt::CaseInsensitive) == 0 ||
           cmds[0].compare("vodport", Qt::CaseInsensitive) == 0) {
            emit routeOut(msg);
        } else {
            QString item;
            foreach(item, cmds) {
                if(item.startsWith(_raspcmd_prefix, Qt::CaseInsensitive)) {
                    emit routeOut(_parsecmd(item));
                }
            }
        }
    }
}

QMap<QString, QString> ControlClient::_parsecmd(QString cmdstr) {
    QMap<QString, QString> cmdmap;
    cmdmap.clear();
    QString cmdrasp = cmdstr.remove(_raspcmd_prefix).trimmed();
    QStringList paralist = cmdrasp.split("-");

    QString cmdopt;
    foreach (cmdopt, paralist) {
        if(cmdopt.startsWith("w ", Qt::CaseInsensitive)) {
            cmdmap["width"] = _parsepara(cmdopt);
        }
        if(cmdopt.startsWith("h ", Qt::CaseInsensitive)) {
            cmdmap["height"] = _parsepara(cmdopt);
            qDebug() << cmdopt;
        }

        if(cmdopt.startsWith("b ", Qt::CaseInsensitive)) {
            cmdmap["bitrate"] = _parsepara(cmdopt);
        }
        if(cmdopt.startsWith("fps ", Qt::CaseInsensitive)) {
            cmdmap["fps"] = _parsepara(cmdopt);
        }
        if(cmdopt.startsWith("br ", Qt::CaseInsensitive)) {
            cmdmap["brightness"] = _parsepara(cmdopt);
        }
    }
    qDebug() << cmdmap;
    return cmdmap;
}

QString ControlClient::_parsepara(QString para) {
    para = para.trimmed();
    QStringList finlist;
    finlist.clear();
    finlist = para.split(" ");
    if(finlist.length() == 2) {
        return finlist.at(1);
    }
    return "";
}
