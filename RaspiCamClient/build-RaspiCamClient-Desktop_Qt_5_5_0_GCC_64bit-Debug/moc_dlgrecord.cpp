/****************************************************************************
** Meta object code from reading C++ file 'dlgrecord.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dlgrecord.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgrecord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DlgRecord_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgRecord_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgRecord_t qt_meta_stringdata_DlgRecord = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DlgRecord"
QT_MOC_LITERAL(1, 10, 22), // "on_btn_refresh_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "records"
QT_MOC_LITERAL(4, 42, 32), // "on_tbl_records_cellDoubleClicked"
QT_MOC_LITERAL(5, 75, 3), // "row"
QT_MOC_LITERAL(6, 79, 6), // "column"
QT_MOC_LITERAL(7, 86, 8), // "delclick"
QT_MOC_LITERAL(8, 95, 6), // "row_id"
QT_MOC_LITERAL(9, 102, 10) // "setplaypos"

    },
    "DlgRecord\0on_btn_refresh_clicked\0\0"
    "records\0on_tbl_records_cellDoubleClicked\0"
    "row\0column\0delclick\0row_id\0setplaypos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgRecord[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       4,    2,   43,    2, 0x08 /* Private */,
       7,    1,   48,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void DlgRecord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DlgRecord *_t = static_cast<DlgRecord *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_refresh_clicked(); break;
        case 1: _t->records((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_tbl_records_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->delclick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setplaypos(); break;
        default: ;
        }
    }
}

const QMetaObject DlgRecord::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgRecord.data,
      qt_meta_data_DlgRecord,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DlgRecord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgRecord::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DlgRecord.stringdata0))
        return static_cast<void*>(const_cast< DlgRecord*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgRecord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
