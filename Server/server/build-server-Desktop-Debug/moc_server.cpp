/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_server[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,   29,   29,   29, 0x0a,
      30,   29,   29,   29, 0x0a,
      49,   29,   29,   29, 0x0a,
      66,   29,   29,   29, 0x0a,
      79,   29,   29,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_server[] = {
    "server\0on_starting_clicked()\0\0"
    "acceptConnection()\0slotReadClient()\0"
    "runCommand()\0programDevice()\0"
};

void server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        server *_t = static_cast<server *>(_o);
        switch (_id) {
        case 0: _t->on_starting_clicked(); break;
        case 1: _t->acceptConnection(); break;
        case 2: _t->slotReadClient(); break;
        case 3: _t->runCommand(); break;
        case 4: _t->programDevice(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData server::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject server::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_server,
      qt_meta_data_server, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &server::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_server))
        return static_cast<void*>(const_cast< server*>(this));
    return QWidget::qt_metacast(_clname);
}

int server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
