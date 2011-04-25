/****************************************************************************
** Meta object code from reading C++ file 'mainwindowimpl.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindowimpl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowimpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowImpl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      24,   15,   15,   15, 0x08,
      36,   15,   15,   15, 0x08,
      48,   15,   15,   15, 0x08,
      60,   15,   15,   15, 0x08,
      70,   15,   15,   15, 0x08,
      81,   15,   15,   15, 0x08,
     100,   15,   15,   15, 0x08,
     118,   15,   15,   15, 0x08,
     139,   15,   15,   15, 0x08,
     164,  162,  158,   15, 0x08,
     196,  162,  158,   15, 0x08,
     230,   15,   15,   15, 0x08,
     249,  247,   15,   15, 0x08,
     268,   15,   15,   15, 0x08,
     291,   15,   15,   15, 0x08,
     312,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowImpl[] = {
    "MainWindowImpl\0\0count()\0stopTimer()\0"
    "pauseGame()\0startGame()\0process()\0"
    "playNext()\0init_interpreter()\0"
    "readInterpreter()\0interpreterStarted()\0"
    "interpreterError()\0int\0,\0"
    "get_code_score(QString,QString)\0"
    "get_output_score(QString,QString)\0"
    "loadChallenges()\0i\0playChallenge(int)\0"
    "printToOutput(QString)\0printToCode(QString)\0"
    "printToChallenge(QString)\0"
};

const QMetaObject MainWindowImpl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowImpl,
      qt_meta_data_MainWindowImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindowImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowImpl))
        return static_cast<void*>(const_cast< MainWindowImpl*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< MainWindowImpl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: count(); break;
        case 1: stopTimer(); break;
        case 2: pauseGame(); break;
        case 3: startGame(); break;
        case 4: process(); break;
        case 5: playNext(); break;
        case 6: init_interpreter(); break;
        case 7: readInterpreter(); break;
        case 8: interpreterStarted(); break;
        case 9: interpreterError(); break;
        case 10: { int _r = get_code_score((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = get_output_score((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: loadChallenges(); break;
        case 13: playChallenge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: printToOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: printToCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: printToChallenge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
