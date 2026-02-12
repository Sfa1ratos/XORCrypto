/****************************************************************************
** Meta object code from reading C++ file 'hardwork.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../hardwork.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8HardWorkE_t {};
} // unnamed namespace

template <> constexpr inline auto HardWork::qt_create_metaobjectdata<qt_meta_tag_ZN8HardWorkE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "HardWork",
        "timerstop",
        "",
        "timerStart",
        "starting",
        "finished",
        "InitPrBar",
        "wInitPrBar",
        "filePrBarValue",
        "prBarValue",
        "wFilePrBarValue",
        "wPrBarValue",
        "message",
        "Working"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'timerstop'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timerStart'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'starting'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'InitPrBar'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'wInitPrBar'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'filePrBarValue'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'prBarValue'
        QtMocHelpers::SignalData<void(double)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Signal 'wFilePrBarValue'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'wPrBarValue'
        QtMocHelpers::SignalData<void(double)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 2 },
        }}),
        // Signal 'message'
        QtMocHelpers::SignalData<void(QString)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'Working'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<HardWork, qt_meta_tag_ZN8HardWorkE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject HardWork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8HardWorkE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8HardWorkE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8HardWorkE_t>.metaTypes,
    nullptr
} };

void HardWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HardWork *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->timerstop(); break;
        case 1: _t->timerStart(); break;
        case 2: _t->starting(); break;
        case 3: _t->finished(); break;
        case 4: _t->InitPrBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->wInitPrBar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->filePrBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->prBarValue((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 8: _t->wFilePrBarValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->wPrBarValue((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->Working(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)()>(_a, &HardWork::timerstop, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)()>(_a, &HardWork::timerStart, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)()>(_a, &HardWork::starting, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)()>(_a, &HardWork::finished, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(int )>(_a, &HardWork::InitPrBar, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(int )>(_a, &HardWork::wInitPrBar, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(int )>(_a, &HardWork::filePrBarValue, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(double )>(_a, &HardWork::prBarValue, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(int )>(_a, &HardWork::wFilePrBarValue, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(double )>(_a, &HardWork::wPrBarValue, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (HardWork::*)(QString )>(_a, &HardWork::message, 10))
            return;
    }
}

const QMetaObject *HardWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HardWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8HardWorkE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HardWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void HardWork::timerstop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HardWork::timerStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HardWork::starting()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HardWork::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void HardWork::InitPrBar(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void HardWork::wInitPrBar(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void HardWork::filePrBarValue(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void HardWork::prBarValue(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void HardWork::wFilePrBarValue(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void HardWork::wPrBarValue(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void HardWork::message(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}
QT_WARNING_POP
