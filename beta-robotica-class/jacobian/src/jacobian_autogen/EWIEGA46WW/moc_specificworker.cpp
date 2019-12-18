/****************************************************************************
** Meta object code from reading C++ file 'specificworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../specificworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specificworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpecificWorker_t {
    QByteArrayData data[15];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpecificWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpecificWorker_t qt_meta_stringdata_SpecificWorker = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SpecificWorker"
QT_MOC_LITERAL(1, 15, 7), // "compute"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "leftSlot"
QT_MOC_LITERAL(4, 33, 9), // "rightSlot"
QT_MOC_LITERAL(5, 43, 6), // "upSlot"
QT_MOC_LITERAL(6, 50, 8), // "downSlot"
QT_MOC_LITERAL(7, 59, 9), // "frontSlot"
QT_MOC_LITERAL(8, 69, 8), // "backSlot"
QT_MOC_LITERAL(9, 78, 11), // "rotLeftSlot"
QT_MOC_LITERAL(10, 90, 12), // "rotRightSlot"
QT_MOC_LITERAL(11, 103, 6), // "goHome"
QT_MOC_LITERAL(12, 110, 11), // "changeSpeed"
QT_MOC_LITERAL(13, 122, 10), // "initialize"
QT_MOC_LITERAL(14, 133, 6) // "period"

    },
    "SpecificWorker\0compute\0\0leftSlot\0"
    "rightSlot\0upSlot\0downSlot\0frontSlot\0"
    "backSlot\0rotLeftSlot\0rotRightSlot\0"
    "goHome\0changeSpeed\0initialize\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpecificWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    1,   84,    2, 0x0a /* Public */,
      13,    1,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void SpecificWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpecificWorker *_t = static_cast<SpecificWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compute(); break;
        case 1: _t->leftSlot(); break;
        case 2: _t->rightSlot(); break;
        case 3: _t->upSlot(); break;
        case 4: _t->downSlot(); break;
        case 5: _t->frontSlot(); break;
        case 6: _t->backSlot(); break;
        case 7: _t->rotLeftSlot(); break;
        case 8: _t->rotRightSlot(); break;
        case 9: _t->goHome(); break;
        case 10: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SpecificWorker::staticMetaObject = {
    { &GenericWorker::staticMetaObject, qt_meta_stringdata_SpecificWorker.data,
      qt_meta_data_SpecificWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SpecificWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpecificWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpecificWorker.stringdata0))
        return static_cast<void*>(this);
    return GenericWorker::qt_metacast(_clname);
}

int SpecificWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
