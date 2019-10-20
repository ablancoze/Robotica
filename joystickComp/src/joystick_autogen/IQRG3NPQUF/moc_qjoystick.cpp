/****************************************************************************
** Meta object code from reading C++ file 'qjoystick.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../classes/qjoystick/qjoystick.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qjoystick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QJoyStick[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   10,   10,   10, 0x0a,
      59,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QJoyStick[] = {
    "QJoyStick\0\0value,type,number\0"
    "inputEvent(int,int,int)\0run()\0stop()\0"
};

void QJoyStick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QJoyStick *_t = static_cast<QJoyStick *>(_o);
        switch (_id) {
        case 0: _t->inputEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->run(); break;
        case 2: _t->stop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QJoyStick::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QJoyStick::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QJoyStick,
      qt_meta_data_QJoyStick, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QJoyStick::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QJoyStick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QJoyStick::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QJoyStick))
        return static_cast<void*>(const_cast< QJoyStick*>(this));
    return QThread::qt_metacast(_clname);
}

int QJoyStick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QJoyStick::inputEvent(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
