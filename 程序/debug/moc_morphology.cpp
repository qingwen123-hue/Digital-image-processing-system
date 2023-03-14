/****************************************************************************
** Meta object code from reading C++ file 'morphology.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test2/morphology.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'morphology.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Morphology_t {
    QByteArrayData data[14];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Morphology_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Morphology_t qt_meta_stringdata_Morphology = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Morphology"
QT_MOC_LITERAL(1, 11, 11), // "ReceiveCode"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "code"
QT_MOC_LITERAL(4, 29, 24), // "on_ErodingButton_clicked"
QT_MOC_LITERAL(5, 54, 25), // "on_DilatingButton_clicked"
QT_MOC_LITERAL(6, 80, 21), // "on_SaveButton_clicked"
QT_MOC_LITERAL(7, 102, 24), // "on_OpeningButton_clicked"
QT_MOC_LITERAL(8, 127, 24), // "on_ClosingButton_clicked"
QT_MOC_LITERAL(9, 152, 20), // "on_TopButton_clicked"
QT_MOC_LITERAL(10, 173, 22), // "on_BlackButton_clicked"
QT_MOC_LITERAL(11, 196, 25), // "on_GradientButton_clicked"
QT_MOC_LITERAL(12, 222, 12), // "CameraHandle"
QT_MOC_LITERAL(13, 235, 10) // "EditHander"

    },
    "Morphology\0ReceiveCode\0\0code\0"
    "on_ErodingButton_clicked\0"
    "on_DilatingButton_clicked\0"
    "on_SaveButton_clicked\0on_OpeningButton_clicked\0"
    "on_ClosingButton_clicked\0on_TopButton_clicked\0"
    "on_BlackButton_clicked\0on_GradientButton_clicked\0"
    "CameraHandle\0EditHander"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Morphology[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    0,   72,    2, 0x08 /* Private */,
       5,    0,   73,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Morphology::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Morphology *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveCode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_ErodingButton_clicked(); break;
        case 2: _t->on_DilatingButton_clicked(); break;
        case 3: _t->on_SaveButton_clicked(); break;
        case 4: _t->on_OpeningButton_clicked(); break;
        case 5: _t->on_ClosingButton_clicked(); break;
        case 6: _t->on_TopButton_clicked(); break;
        case 7: _t->on_BlackButton_clicked(); break;
        case 8: _t->on_GradientButton_clicked(); break;
        case 9: _t->CameraHandle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->EditHander(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Morphology::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Morphology.data,
    qt_meta_data_Morphology,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Morphology::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Morphology::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Morphology.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Morphology::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
