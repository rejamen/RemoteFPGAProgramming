/****************************************************************************
** Meta object code from reading C++ file 'tcprequest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcprequest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcprequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpRequest_t {
    QByteArrayData data[10];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpRequest_t qt_meta_stringdata_TcpRequest = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TcpRequest"
QT_MOC_LITERAL(1, 11, 6), // "sigmsg"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "msg"
QT_MOC_LITERAL(4, 23, 4), // "done"
QT_MOC_LITERAL(5, 28, 12), // "disconnected"
QT_MOC_LITERAL(6, 41, 7), // "readall"
QT_MOC_LITERAL(7, 49, 5), // "error"
QT_MOC_LITERAL(8, 55, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 84, 12) // "readfinished"

    },
    "TcpRequest\0sigmsg\0\0msg\0done\0disconnected\0"
    "readall\0error\0QAbstractSocket::SocketError\0"
    "readfinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    7,
    QMetaType::Void,

       0        // eod
};

void TcpRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpRequest *_t = static_cast<TcpRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigmsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->done(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->readall(); break;
        case 4: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->readfinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpRequest::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRequest::sigmsg)) {
                *result = 0;
            }
        }
        {
            typedef void (TcpRequest::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRequest::done)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TcpRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpRequest.data,
      qt_meta_data_TcpRequest,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpRequest.stringdata0))
        return static_cast<void*>(const_cast< TcpRequest*>(this));
    return QObject::qt_metacast(_clname);
}

int TcpRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TcpRequest::sigmsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpRequest::done()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
