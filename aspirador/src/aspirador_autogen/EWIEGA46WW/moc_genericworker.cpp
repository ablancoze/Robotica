/****************************************************************************
** Meta object code from reading C++ file 'genericworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../genericworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genericworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GenericWorker_t {
    QByteArrayData data[12];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GenericWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GenericWorker_t qt_meta_stringdata_GenericWorker = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GenericWorker"
QT_MOC_LITERAL(1, 14, 4), // "kill"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 19), // "initializetocompute"
QT_MOC_LITERAL(4, 40, 16), // "computetocompute"
QT_MOC_LITERAL(5, 57, 17), // "computetofinalize"
QT_MOC_LITERAL(6, 75, 10), // "sm_compute"
QT_MOC_LITERAL(7, 86, 13), // "sm_initialize"
QT_MOC_LITERAL(8, 100, 11), // "sm_finalize"
QT_MOC_LITERAL(9, 112, 7), // "compute"
QT_MOC_LITERAL(10, 120, 10), // "initialize"
QT_MOC_LITERAL(11, 131, 6) // "period"

    },
    "GenericWorker\0kill\0\0initializetocompute\0"
    "computetocompute\0computetofinalize\0"
    "sm_compute\0sm_initialize\0sm_finalize\0"
    "compute\0initialize\0period"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenericWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void GenericWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenericWorker *_t = static_cast<GenericWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->kill(); break;
        case 1: _t->initializetocompute(); break;
        case 2: _t->computetocompute(); break;
        case 3: _t->computetofinalize(); break;
        case 4: _t->sm_compute(); break;
        case 5: _t->sm_initialize(); break;
        case 6: _t->sm_finalize(); break;
        case 7: _t->compute(); break;
        case 8: _t->initialize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GenericWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericWorker::kill)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GenericWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericWorker::initializetocompute)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GenericWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericWorker::computetocompute)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GenericWorker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GenericWorker::computetofinalize)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject GenericWorker::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GenericWorker.data,
      qt_meta_data_GenericWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GenericWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenericWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GenericWorker.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_guiDlg"))
        return static_cast< Ui_guiDlg*>(this);
    return QWidget::qt_metacast(_clname);
}

int GenericWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GenericWorker::kill()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GenericWorker::initializetocompute()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GenericWorker::computetocompute()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GenericWorker::computetofinalize()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
