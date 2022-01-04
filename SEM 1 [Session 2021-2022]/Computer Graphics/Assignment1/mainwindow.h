#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_resetButton_clicked();

    void on_setGridButton_clicked();

    void on_DDALine_clicked();

    void on_bresenhamLine_clicked();

    void on_showAxes_clicked();

    void on_bresenhamCircle_clicked();

    void on_draw_ellipse_clicked();

    void on_resetUtil_clicked();

    void animationDelay();

    void on_polarCircle_clicked();

    void on_pushButton_clicked();

    void on_boundaryFill_clicked();

    void on_floodFill_clicked();

    void floodfillutil(int, int, int, int, int);

    void boundaryfillutil(int, int, QRgb, int, int, int);

    void on_draw_ellipse_polar_clicked();

    void on_draw_ellipse_bresenham_clicked();

    void on_scanLineFill_clicked();

    void on_setVertex_clicked();

    void on_clearVertex_clicked();

    void storeEdgeInTable (int,int, int, int);

    void initEdgeTable();

    void poly_draw(std::vector<std::pair<int,int> >, int, int, int);

    void on_translation_clicked();

    void on_rotation_clicked();

    void on_scaling_clicked();

    void on_shearing_clicked();

    void on_reflection_clicked();

    void on_reflectionX_clicked();

    void on_reflectionY_clicked();

    void on_reflectionO_clicked();

    void on_setCorner1_clicked();

    void on_setCorner2_clicked();

    void draw_Window();

    int computeCode(int , int );

    void cohenSutherlandClip(int , int ,int , int );

    void on_lineClippping_clicked();

    void on_polygonClipping_clicked();

    void suthHodgClip();

    void clip(int, int, int, int);

    int y_intersect(int, int, int, int, int, int, int , int);

    int x_intersect(int, int, int, int, int, int, int , int);

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    QPoint cp1, cp2;
    void point(int,int,int, int, int);
    void DDAline(int, int, int);
};

#endif // MAINWINDOW_H
