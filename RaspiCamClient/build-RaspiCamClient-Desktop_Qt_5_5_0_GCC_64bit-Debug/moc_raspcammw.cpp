/****************************************************************************
** Meta object code from reading C++ file 'raspcammw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../raspcammw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'raspcammw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RaspCamMW_t {
    QByteArrayData data[26];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RaspCamMW_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RaspCamMW_t qt_meta_stringdata_RaspCamMW = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RaspCamMW"
QT_MOC_LITERAL(1, 10, 18), // "on_btnScan_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "on_btnStart_clicked"
QT_MOC_LITERAL(4, 50, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(5, 69, 20), // "on_btnRecord_clicked"
QT_MOC_LITERAL(6, 90, 7), // "recvmsg"
QT_MOC_LITERAL(7, 98, 3), // "msg"
QT_MOC_LITERAL(8, 102, 9), // "recvvcmds"
QT_MOC_LITERAL(9, 112, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(10, 134, 6), // "params"
QT_MOC_LITERAL(11, 141, 10), // "recvcmdstr"
QT_MOC_LITERAL(12, 152, 3), // "cmd"
QT_MOC_LITERAL(13, 156, 10), // "laterstart"
QT_MOC_LITERAL(14, 167, 11), // "drawprocess"
QT_MOC_LITERAL(15, 179, 22), // "on_btn_confirm_clicked"
QT_MOC_LITERAL(16, 202, 24), // "on_btn_remoteRcd_clicked"
QT_MOC_LITERAL(17, 227, 24), // "on_btn_getrecord_clicked"
QT_MOC_LITERAL(18, 252, 18), // "on_btnSnap_clicked"
QT_MOC_LITERAL(19, 271, 10), // "fileOpened"
QT_MOC_LITERAL(20, 282, 15), // "connectToServer"
QT_MOC_LITERAL(21, 298, 6), // "onSend"
QT_MOC_LITERAL(22, 305, 12), // "displayError"
QT_MOC_LITERAL(23, 318, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(24, 347, 11), // "socketError"
QT_MOC_LITERAL(25, 359, 14) // "slotReadClient"

    },
    "RaspCamMW\0on_btnScan_clicked\0\0"
    "on_btnStart_clicked\0on_btnStop_clicked\0"
    "on_btnRecord_clicked\0recvmsg\0msg\0"
    "recvvcmds\0QMap<QString,QString>\0params\0"
    "recvcmdstr\0cmd\0laterstart\0drawprocess\0"
    "on_btn_confirm_clicked\0on_btn_remoteRcd_clicked\0"
    "on_btn_getrecord_clicked\0on_btnSnap_clicked\0"
    "fileOpened\0connectToServer\0onSend\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "socketError\0slotReadClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RaspCamMW[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    1,  108,    2, 0x08 /* Private */,
       8,    1,  111,    2, 0x08 /* Private */,
      11,    1,  114,    2, 0x08 /* Private */,
      13,    0,  117,    2, 0x08 /* Private */,
      14,    0,  118,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x08 /* Private */,
      16,    0,  120,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,
      18,    0,  122,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,
      22,    1,  126,    2, 0x08 /* Private */,
      25,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,

       0        // eod
};

void RaspCamMW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RaspCamMW *_t = static_cast<RaspCamMW *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnScan_clicked(); break;
        case 1: _t->on_btnStart_clicked(); break;
        case 2: _t->on_btnStop_clicked(); break;
        case 3: _t->on_btnRecord_clicked(); break;
        case 4: _t->recvmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->recvvcmds((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1]))); break;
        case 6: _t->recvcmdstr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->laterstart(); break;
        case 8: _t->drawprocess(); break;
        case 9: _t->on_btn_confirm_clicked(); break;
        case 10: _t->on_btn_remoteRcd_clicked(); break;
        case 11: _t->on_btn_getrecord_clicked(); break;
        case 12: _t->on_btnSnap_clicked(); break;
        case 13: _t->fileOpened(); break;
        case 14: _t->connectToServer(); break;
        case 15: _t->onSend(); break;
        case 16: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 17: _t->slotReadClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject RaspCamMW::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RaspCamMW.data,
      qt_meta_data_RaspCamMW,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RaspCamMW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RaspCamMW::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RaspCamMW.stringdata0))
        return static_cast<void*>(const_cast< RaspCamMW*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RaspCamMW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
