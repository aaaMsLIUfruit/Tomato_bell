/****************************************************************************
** Meta object code from reading C++ file 'mainClock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainClock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainClock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mainclock_t {
    QByteArrayData data[13];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mainclock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mainclock_t qt_meta_stringdata_Mainclock = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Mainclock"
QT_MOC_LITERAL(1, 10, 13), // "returntoClock"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "togglePausePlay"
QT_MOC_LITERAL(4, 41, 11), // "updateTimer"
QT_MOC_LITERAL(5, 53, 16), // "updatePauseTimer"
QT_MOC_LITERAL(6, 70, 15), // "resumeMainTimer"
QT_MOC_LITERAL(7, 86, 19), // "showPauseMessageBox"
QT_MOC_LITERAL(8, 106, 25), // "updatePauseMessageBoxText"
QT_MOC_LITERAL(9, 132, 21), // "showFailureMessageBox"
QT_MOC_LITERAL(10, 154, 17), // "onContinueClicked"
QT_MOC_LITERAL(11, 172, 16), // "onRestartClicked"
QT_MOC_LITERAL(12, 189, 13) // "onBackClicked"

    },
    "Mainclock\0returntoClock\0\0togglePausePlay\0"
    "updateTimer\0updatePauseTimer\0"
    "resumeMainTimer\0showPauseMessageBox\0"
    "updatePauseMessageBoxText\0"
    "showFailureMessageBox\0onContinueClicked\0"
    "onRestartClicked\0onBackClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mainclock[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

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

       0        // eod
};

void Mainclock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mainclock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returntoClock(); break;
        case 1: _t->togglePausePlay(); break;
        case 2: _t->updateTimer(); break;
        case 3: _t->updatePauseTimer(); break;
        case 4: _t->resumeMainTimer(); break;
        case 5: _t->showPauseMessageBox(); break;
        case 6: _t->updatePauseMessageBoxText(); break;
        case 7: _t->showFailureMessageBox(); break;
        case 8: _t->onContinueClicked(); break;
        case 9: _t->onRestartClicked(); break;
        case 10: _t->onBackClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mainclock::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mainclock::returntoClock)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Mainclock::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Mainclock.data,
    qt_meta_data_Mainclock,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mainclock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mainclock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mainclock.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mainclock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Mainclock::returntoClock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
