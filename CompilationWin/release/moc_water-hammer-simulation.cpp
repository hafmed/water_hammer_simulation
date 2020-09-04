/****************************************************************************
** Meta object code from reading C++ file 'water-hammer-simulation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/water-hammer-simulation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'water-hammer-simulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_water_hammer_simulation_t {
    QByteArrayData data[13];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_water_hammer_simulation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_water_hammer_simulation_t qt_meta_stringdata_water_hammer_simulation = {
    {
QT_MOC_LITERAL(0, 0, 23), // "water_hammer_simulation"
QT_MOC_LITERAL(1, 24, 7), // "plotHAF"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 1), // "k"
QT_MOC_LITERAL(4, 35, 27), // "changeintervalTimeAnimation"
QT_MOC_LITERAL(5, 63, 6), // "interv"
QT_MOC_LITERAL(6, 70, 11), // "plotHAFTime"
QT_MOC_LITERAL(7, 82, 14), // "StartAnimation"
QT_MOC_LITERAL(8, 97, 13), // "intialplotHAF"
QT_MOC_LITERAL(9, 111, 12), // "plotHAFVanne"
QT_MOC_LITERAL(10, 124, 8), // "recalcul"
QT_MOC_LITERAL(11, 133, 23), // "copy_table_in_Clipboard"
QT_MOC_LITERAL(12, 157, 19) // "affichage_resultats"

    },
    "water_hammer_simulation\0plotHAF\0\0k\0"
    "changeintervalTimeAnimation\0interv\0"
    "plotHAFTime\0StartAnimation\0intialplotHAF\0"
    "plotHAFVanne\0recalcul\0copy_table_in_Clipboard\0"
    "affichage_resultats"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_water_hammer_simulation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void water_hammer_simulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        water_hammer_simulation *_t = static_cast<water_hammer_simulation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plotHAF((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeintervalTimeAnimation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->plotHAFTime(); break;
        case 3: _t->StartAnimation(); break;
        case 4: _t->intialplotHAF(); break;
        case 5: _t->plotHAFVanne(); break;
        case 6: _t->recalcul(); break;
        case 7: _t->copy_table_in_Clipboard(); break;
        case 8: _t->affichage_resultats(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject water_hammer_simulation::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_water_hammer_simulation.data,
    qt_meta_data_water_hammer_simulation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *water_hammer_simulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *water_hammer_simulation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_water_hammer_simulation.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int water_hammer_simulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
