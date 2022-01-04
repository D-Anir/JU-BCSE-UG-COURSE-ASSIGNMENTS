/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Assignment1/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[106];
    char stringdata0[1006];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 17), // "showMousePosition"
QT_MOC_LITERAL(44, 7), // "QPoint&"
QT_MOC_LITERAL(52, 3), // "pos"
QT_MOC_LITERAL(56, 20), // "on_show_axes_clicked"
QT_MOC_LITERAL(77, 21), // "on_set_point1_clicked"
QT_MOC_LITERAL(99, 21), // "on_set_point2_clicked"
QT_MOC_LITERAL(121, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(144, 24), // "on_setGridButton_clicked"
QT_MOC_LITERAL(169, 18), // "on_DDALine_clicked"
QT_MOC_LITERAL(188, 24), // "on_bresenhamLine_clicked"
QT_MOC_LITERAL(213, 19), // "on_showAxes_clicked"
QT_MOC_LITERAL(233, 26), // "on_bresenhamCircle_clicked"
QT_MOC_LITERAL(260, 23), // "on_draw_ellipse_clicked"
QT_MOC_LITERAL(284, 20), // "on_resetUtil_clicked"
QT_MOC_LITERAL(305, 14), // "animationDelay"
QT_MOC_LITERAL(320, 22), // "on_polarCircle_clicked"
QT_MOC_LITERAL(343, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(365, 23), // "on_boundaryFill_clicked"
QT_MOC_LITERAL(389, 20), // "on_floodFill_clicked"
QT_MOC_LITERAL(410, 13), // "floodfillutil"
QT_MOC_LITERAL(424, 16), // "boundaryfillutil"
QT_MOC_LITERAL(441, 4), // "QRgb"
QT_MOC_LITERAL(446, 29), // "on_draw_ellipse_polar_clicked"
QT_MOC_LITERAL(476, 33), // "on_draw_ellipse_bresenham_cli..."
QT_MOC_LITERAL(510, 23), // "on_scanLineFill_clicked"
QT_MOC_LITERAL(534, 20), // "on_setVertex_clicked"
QT_MOC_LITERAL(555, 22), // "on_clearVertex_clicked"
QT_MOC_LITERAL(578, 16), // "storeEdgeInTable"
QT_MOC_LITERAL(595, 13), // "initEdgeTable"
QT_MOC_LITERAL(609, 9), // "poly_draw"
QT_MOC_LITERAL(619, 31), // "std::vector<std::pair<int,int>>"
QT_MOC_LITERAL(651, 22), // "on_translation_clicked"
QT_MOC_LITERAL(674, 19), // "on_rotation_clicked"
QT_MOC_LITERAL(694, 18), // "on_scaling_clicked"
QT_MOC_LITERAL(713, 19), // "on_shearing_clicked"
QT_MOC_LITERAL(733, 21), // "on_reflection_clicked"
QT_MOC_LITERAL(755, 22), // "on_reflectionX_clicked"
QT_MOC_LITERAL(778, 22), // "on_reflectionY_clicked"
QT_MOC_LITERAL(801, 22), // "on_reflectionO_clicked"
QT_MOC_LITERAL(824, 21), // "on_setCorner1_clicked"
QT_MOC_LITERAL(846, 21), // "on_setCorner2_clicked"
QT_MOC_LITERAL(868, 11), // "draw_Window"
QT_MOC_LITERAL(880, 11), // "computeCode"
QT_MOC_LITERAL(892, 19), // "cohenSutherlandClip"
QT_MOC_LITERAL(912, 24), // "on_lineClippping_clicked"
QT_MOC_LITERAL(937, 26), // "on_polygonClipping_clicked"
QT_MOC_LITERAL(964, 12), // "suthHodgClip"
QT_MOC_LITERAL(977, 4), // "clip"
QT_MOC_LITERAL(982, 11), // "y_intersect"
QT_MOC_LITERAL(994, 11) // "x_intersect"

    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0on_show_axes_clicked\0"
    "on_set_point1_clicked\0on_set_point2_clicked\0"
    "on_resetButton_clicked\0on_setGridButton_clicked\0"
    "on_DDALine_clicked\0on_bresenhamLine_clicked\0"
    "on_showAxes_clicked\0on_bresenhamCircle_clicked\0"
    "on_draw_ellipse_clicked\0on_resetUtil_clicked\0"
    "animationDelay\0on_polarCircle_clicked\0"
    "on_pushButton_clicked\0on_boundaryFill_clicked\0"
    "on_floodFill_clicked\0floodfillutil\0"
    "boundaryfillutil\0QRgb\0"
    "on_draw_ellipse_polar_clicked\0"
    "on_draw_ellipse_bresenham_clicked\0"
    "on_scanLineFill_clicked\0on_setVertex_clicked\0"
    "on_clearVertex_clicked\0storeEdgeInTable\0"
    "initEdgeTable\0poly_draw\0"
    "std::vector<std::pair<int,int>>\0"
    "on_translation_clicked\0on_rotation_clicked\0"
    "on_scaling_clicked\0on_shearing_clicked\0"
    "on_reflection_clicked\0on_reflectionX_clicked\0"
    "on_reflectionY_clicked\0on_reflectionO_clicked\0"
    "on_setCorner1_clicked\0on_setCorner2_clicked\0"
    "draw_Window\0computeCode\0cohenSutherlandClip\0"
    "on_lineClippping_clicked\0"
    "on_polygonClipping_clicked\0suthHodgClip\0"
    "clip\0y_intersect\0x_intersect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  296,    2, 0x0a,    0 /* Public */,
       3,    1,  297,    2, 0x0a,    1 /* Public */,
       6,    0,  300,    2, 0x08,    3 /* Private */,
       7,    0,  301,    2, 0x08,    4 /* Private */,
       8,    0,  302,    2, 0x08,    5 /* Private */,
       9,    0,  303,    2, 0x08,    6 /* Private */,
      10,    0,  304,    2, 0x08,    7 /* Private */,
      11,    0,  305,    2, 0x08,    8 /* Private */,
      12,    0,  306,    2, 0x08,    9 /* Private */,
      13,    0,  307,    2, 0x08,   10 /* Private */,
      14,    0,  308,    2, 0x08,   11 /* Private */,
      15,    0,  309,    2, 0x08,   12 /* Private */,
      16,    0,  310,    2, 0x08,   13 /* Private */,
      17,    0,  311,    2, 0x08,   14 /* Private */,
      18,    0,  312,    2, 0x08,   15 /* Private */,
      19,    0,  313,    2, 0x08,   16 /* Private */,
      20,    0,  314,    2, 0x08,   17 /* Private */,
      21,    0,  315,    2, 0x08,   18 /* Private */,
      22,    5,  316,    2, 0x08,   19 /* Private */,
      23,    6,  327,    2, 0x08,   25 /* Private */,
      25,    0,  340,    2, 0x08,   32 /* Private */,
      26,    0,  341,    2, 0x08,   33 /* Private */,
      27,    0,  342,    2, 0x08,   34 /* Private */,
      28,    0,  343,    2, 0x08,   35 /* Private */,
      29,    0,  344,    2, 0x08,   36 /* Private */,
      30,    4,  345,    2, 0x08,   37 /* Private */,
      31,    0,  354,    2, 0x08,   42 /* Private */,
      32,    4,  355,    2, 0x08,   43 /* Private */,
      34,    0,  364,    2, 0x08,   48 /* Private */,
      35,    0,  365,    2, 0x08,   49 /* Private */,
      36,    0,  366,    2, 0x08,   50 /* Private */,
      37,    0,  367,    2, 0x08,   51 /* Private */,
      38,    0,  368,    2, 0x08,   52 /* Private */,
      39,    0,  369,    2, 0x08,   53 /* Private */,
      40,    0,  370,    2, 0x08,   54 /* Private */,
      41,    0,  371,    2, 0x08,   55 /* Private */,
      42,    0,  372,    2, 0x08,   56 /* Private */,
      43,    0,  373,    2, 0x08,   57 /* Private */,
      44,    0,  374,    2, 0x08,   58 /* Private */,
      45,    2,  375,    2, 0x08,   59 /* Private */,
      46,    4,  380,    2, 0x08,   62 /* Private */,
      47,    0,  389,    2, 0x08,   67 /* Private */,
      48,    0,  390,    2, 0x08,   68 /* Private */,
      49,    0,  391,    2, 0x08,   69 /* Private */,
      50,    4,  392,    2, 0x08,   70 /* Private */,
      51,    8,  401,    2, 0x08,   75 /* Private */,
      52,    8,  418,    2, 0x08,   84 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 24, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
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
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->on_set_point1_clicked(); break;
        case 4: _t->on_set_point2_clicked(); break;
        case 5: _t->on_resetButton_clicked(); break;
        case 6: _t->on_setGridButton_clicked(); break;
        case 7: _t->on_DDALine_clicked(); break;
        case 8: _t->on_bresenhamLine_clicked(); break;
        case 9: _t->on_showAxes_clicked(); break;
        case 10: _t->on_bresenhamCircle_clicked(); break;
        case 12: _t->on_resetUtil_clicked(); break;
        case 13: _t->animationDelay(); break;
        case 14: _t->on_polarCircle_clicked(); break;
        case 16: _t->on_boundaryFill_clicked(); break;
        case 17: _t->on_floodFill_clicked(); break;
        case 18: _t->floodfillutil((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 19: _t->boundaryfillutil((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QRgb(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 20: _t->on_draw_ellipse_polar_clicked(); break;
        case 21: _t->on_draw_ellipse_bresenham_clicked(); break;
        case 22: _t->on_scanLineFill_clicked(); break;
        case 23: _t->on_setVertex_clicked(); break;
        case 24: _t->on_clearVertex_clicked(); break;
        case 25: _t->storeEdgeInTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 26: _t->initEdgeTable(); break;
        case 27: _t->poly_draw((*reinterpret_cast< std::vector<std::pair<int,int>>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 28: _t->on_translation_clicked(); break;
        case 29: _t->on_rotation_clicked(); break;
        case 30: _t->on_scaling_clicked(); break;
        case 31: _t->on_shearing_clicked(); break;
        case 32: _t->on_reflection_clicked(); break;
        case 33: _t->on_reflectionX_clicked(); break;
        case 34: _t->on_reflectionY_clicked(); break;
        case 35: _t->on_reflectionO_clicked(); break;
        case 36: _t->on_setCorner1_clicked(); break;
        case 37: _t->on_setCorner2_clicked(); break;
        case 38: _t->draw_Window(); break;
        case 39: { int _r = _t->computeCode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->cohenSutherlandClip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 41: _t->on_lineClippping_clicked(); break;
        case 42: _t->on_polygonClipping_clicked(); break;
        case 43: _t->suthHodgClip(); break;
        case 44: _t->clip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 45: { int _r = _t->y_intersect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: { int _r = _t->x_intersect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QRgb, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::pair<int,int> >, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 47;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
