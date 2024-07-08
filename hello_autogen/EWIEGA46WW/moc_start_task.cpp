/****************************************************************************
** Meta object code from reading C++ file 'start_task.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../start_task.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'start_task.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_start_task_t {
    QByteArrayData data[11];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_start_task_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_start_task_t qt_meta_stringdata_start_task = {
    {
QT_MOC_LITERAL(0, 0, 10), // "start_task"
QT_MOC_LITERAL(1, 11, 13), // "returnToClock"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 50, 16), // "on_start_clicked"
QT_MOC_LITERAL(5, 67, 27), // "on_comboBox_editTextChanged"
QT_MOC_LITERAL(6, 95, 4), // "arg1"
QT_MOC_LITERAL(7, 100, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(8, 131, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(9, 155, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 177, 23) // "on_return_to_start_task"

    },
    "start_task\0returnToClock\0\0"
    "on_pushButton_2_clicked\0on_start_clicked\0"
    "on_comboBox_editTextChanged\0arg1\0"
    "on_comboBox_currentTextChanged\0"
    "on_spinBox_valueChanged\0on_pushButton_clicked\0"
    "on_return_to_start_task"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_start_task[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void start_task::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<start_task *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnToClock(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_start_clicked(); break;
        case 3: _t->on_comboBox_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_return_to_start_task(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (start_task::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&start_task::returnToClock)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject start_task::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_start_task.data,
    qt_meta_data_start_task,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *start_task::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *start_task::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_start_task.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int start_task::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void start_task::returnToClock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
