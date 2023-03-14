/****************************************************************************
** Meta object code from reading C++ file 'grayscale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test2/grayscale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grayscale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Grayscale_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Grayscale_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Grayscale_t qt_meta_stringdata_Grayscale = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Grayscale"
QT_MOC_LITERAL(1, 10, 11), // "ReceiveCode"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "code"
QT_MOC_LITERAL(4, 28, 6), // "change"
QT_MOC_LITERAL(5, 35, 5), // "state"
QT_MOC_LITERAL(6, 41, 10), // "EditHander"
QT_MOC_LITERAL(7, 52, 12), // "SliderHander"
QT_MOC_LITERAL(8, 65, 5), // "value"
QT_MOC_LITERAL(9, 71, 21), // "on_SaveButton_clicked"
QT_MOC_LITERAL(10, 93, 12), // "CameraHandle"
QT_MOC_LITERAL(11, 106, 21) // "on_OTSUButton_clicked"

    },
    "Grayscale\0ReceiveCode\0\0code\0change\0"
    "state\0EditHander\0SliderHander\0value\0"
    "on_SaveButton_clicked\0CameraHandle\0"
    "on_OTSUButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grayscale[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Grayscale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Grayscale *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveCode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->EditHander(); break;
        case 3: _t->SliderHander((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_SaveButton_clicked(); break;
        case 5: _t->CameraHandle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_OTSUButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Grayscale::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Grayscale.data,
    qt_meta_data_Grayscale,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Grayscale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Grayscale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Grayscale.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Grayscale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
