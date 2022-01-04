/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *label_6;
    QFrame *x_axis;
    QFrame *y_axis;
    QLabel *label_7;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *DDALine;
    QPushButton *bresenhamLine;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *radiusSpinBox;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QPushButton *setGridButton;
    QPushButton *showAxes;
    QVBoxLayout *verticalLayout;
    QPushButton *resetButton;
    QPushButton *resetUtil;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *time_taken;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QSpinBox *delay;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *polarCircle;
    QPushButton *bresenhamCircle;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSpinBox *ellipse_major_axis;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *ellipse_minor_axis;
    QPushButton *draw_ellipse_bresenham;
    QPushButton *draw_ellipse_polar;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *boundaryFill;
    QPushButton *floodFill;
    QPushButton *scanLineFill;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *setVertex;
    QPushButton *clearVertex;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *xtranslate;
    QSpinBox *ytranslate;
    QSpinBox *yscale;
    QSpinBox *xscale;
    QSpinBox *rotationAngle;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QSpinBox *yshear;
    QSpinBox *xshear;
    QLabel *label_18;
    QLabel *label_19;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *translation;
    QPushButton *rotation;
    QPushButton *scaling;
    QPushButton *shearing;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *reflection;
    QPushButton *reflectionX;
    QPushButton *reflectionY;
    QPushButton *reflectionO;
    QLabel *label_20;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *setCorner1;
    QPushButton *setCorner2;
    QPushButton *lineClippping;
    QPushButton *polygonClipping;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(873, 642);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 450, 450));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 450, 61, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 450, 2));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 2, 450));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 460, 61, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(460, 110, 168, 61));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        set_point1 = new QPushButton(layoutWidget);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));

        gridLayout->addWidget(set_point1, 0, 0, 1, 1);

        set_point2 = new QPushButton(layoutWidget);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));

        gridLayout->addWidget(set_point2, 0, 1, 1, 1);

        DDALine = new QPushButton(layoutWidget);
        DDALine->setObjectName(QString::fromUtf8("DDALine"));

        gridLayout->addWidget(DDALine, 1, 0, 1, 1);

        bresenhamLine = new QPushButton(layoutWidget);
        bresenhamLine->setObjectName(QString::fromUtf8("bresenhamLine"));

        gridLayout->addWidget(bresenhamLine, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(670, 100, 121, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        radiusSpinBox = new QSpinBox(layoutWidget1);
        radiusSpinBox->setObjectName(QString::fromUtf8("radiusSpinBox"));

        horizontalLayout_3->addWidget(radiusSpinBox);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(490, 30, 291, 54));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        setGridButton = new QPushButton(layoutWidget2);
        setGridButton->setObjectName(QString::fromUtf8("setGridButton"));

        gridLayout_4->addWidget(setGridButton, 0, 0, 1, 1);

        showAxes = new QPushButton(layoutWidget2);
        showAxes->setObjectName(QString::fromUtf8("showAxes"));

        gridLayout_4->addWidget(showAxes, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        resetButton = new QPushButton(layoutWidget2);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout->addWidget(resetButton);

        resetUtil = new QPushButton(layoutWidget2);
        resetUtil->setObjectName(QString::fromUtf8("resetUtil"));

        verticalLayout->addWidget(resetUtil);


        gridLayout_4->addLayout(verticalLayout, 0, 2, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(160, 480, 132, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        time_taken = new QLabel(layoutWidget3);
        time_taken->setObjectName(QString::fromUtf8("time_taken"));
        time_taken->setFrameShape(QFrame::Panel);
        time_taken->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(time_taken);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        delay = new QSpinBox(layoutWidget3);
        delay->setObjectName(QString::fromUtf8("delay"));

        horizontalLayout->addWidget(delay);


        verticalLayout_2->addLayout(horizontalLayout);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(690, 130, 82, 52));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        polarCircle = new QPushButton(layoutWidget4);
        polarCircle->setObjectName(QString::fromUtf8("polarCircle"));

        verticalLayout_3->addWidget(polarCircle);

        bresenhamCircle = new QPushButton(layoutWidget4);
        bresenhamCircle->setObjectName(QString::fromUtf8("bresenhamCircle"));

        verticalLayout_3->addWidget(bresenhamCircle);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(660, 200, 157, 118));
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(layoutWidget5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        ellipse_major_axis = new QSpinBox(layoutWidget5);
        ellipse_major_axis->setObjectName(QString::fromUtf8("ellipse_major_axis"));

        horizontalLayout_6->addWidget(ellipse_major_axis);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        ellipse_minor_axis = new QSpinBox(layoutWidget5);
        ellipse_minor_axis->setObjectName(QString::fromUtf8("ellipse_minor_axis"));

        horizontalLayout_7->addWidget(ellipse_minor_axis);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        draw_ellipse_bresenham = new QPushButton(layoutWidget5);
        draw_ellipse_bresenham->setObjectName(QString::fromUtf8("draw_ellipse_bresenham"));

        gridLayout_3->addWidget(draw_ellipse_bresenham, 1, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        draw_ellipse_polar = new QPushButton(layoutWidget5);
        draw_ellipse_polar->setObjectName(QString::fromUtf8("draw_ellipse_polar"));

        verticalLayout_5->addWidget(draw_ellipse_polar);

        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(500, 230, 111, 91));
        verticalLayout_6 = new QVBoxLayout(layoutWidget6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        boundaryFill = new QPushButton(layoutWidget6);
        boundaryFill->setObjectName(QString::fromUtf8("boundaryFill"));

        verticalLayout_4->addWidget(boundaryFill);

        floodFill = new QPushButton(layoutWidget6);
        floodFill->setObjectName(QString::fromUtf8("floodFill"));

        verticalLayout_4->addWidget(floodFill);


        verticalLayout_6->addLayout(verticalLayout_4);

        scanLineFill = new QPushButton(layoutWidget6);
        scanLineFill->setObjectName(QString::fromUtf8("scanLineFill"));

        verticalLayout_6->addWidget(scanLineFill);

        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(470, 200, 168, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        setVertex = new QPushButton(layoutWidget7);
        setVertex->setObjectName(QString::fromUtf8("setVertex"));

        horizontalLayout_2->addWidget(setVertex);

        clearVertex = new QPushButton(layoutWidget7);
        clearVertex->setObjectName(QString::fromUtf8("clearVertex"));

        horizontalLayout_2->addWidget(clearVertex);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(570, 350, 131, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(520, 320, 81, 20));
        xtranslate = new QSpinBox(centralWidget);
        xtranslate->setObjectName(QString::fromUtf8("xtranslate"));
        xtranslate->setGeometry(QRect(520, 400, 31, 21));
        ytranslate = new QSpinBox(centralWidget);
        ytranslate->setObjectName(QString::fromUtf8("ytranslate"));
        ytranslate->setGeometry(QRect(520, 420, 31, 21));
        yscale = new QSpinBox(centralWidget);
        yscale->setObjectName(QString::fromUtf8("yscale"));
        yscale->setGeometry(QRect(680, 420, 31, 21));
        xscale = new QSpinBox(centralWidget);
        xscale->setObjectName(QString::fromUtf8("xscale"));
        xscale->setGeometry(QRect(680, 400, 31, 21));
        rotationAngle = new QSpinBox(centralWidget);
        rotationAngle->setObjectName(QString::fromUtf8("rotationAngle"));
        rotationAngle->setGeometry(QRect(590, 410, 31, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(460, 400, 61, 20));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(460, 420, 61, 20));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(560, 410, 31, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(640, 400, 41, 16));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(640, 420, 41, 16));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(730, 420, 41, 16));
        yshear = new QSpinBox(centralWidget);
        yshear->setObjectName(QString::fromUtf8("yshear"));
        yshear->setGeometry(QRect(770, 420, 31, 21));
        xshear = new QSpinBox(centralWidget);
        xshear->setObjectName(QString::fromUtf8("xshear"));
        xshear->setGeometry(QRect(770, 400, 31, 21));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(730, 400, 41, 16));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(570, 460, 131, 20));
        label_19->setAlignment(Qt::AlignCenter);
        layoutWidget8 = new QWidget(centralWidget);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(460, 371, 351, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        translation = new QPushButton(layoutWidget8);
        translation->setObjectName(QString::fromUtf8("translation"));

        horizontalLayout_4->addWidget(translation);

        rotation = new QPushButton(layoutWidget8);
        rotation->setObjectName(QString::fromUtf8("rotation"));

        horizontalLayout_4->addWidget(rotation);

        scaling = new QPushButton(layoutWidget8);
        scaling->setObjectName(QString::fromUtf8("scaling"));

        horizontalLayout_4->addWidget(scaling);

        shearing = new QPushButton(layoutWidget8);
        shearing->setObjectName(QString::fromUtf8("shearing"));

        horizontalLayout_4->addWidget(shearing);

        layoutWidget9 = new QWidget(centralWidget);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(450, 480, 358, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        reflection = new QPushButton(layoutWidget9);
        reflection->setObjectName(QString::fromUtf8("reflection"));

        horizontalLayout_5->addWidget(reflection);

        reflectionX = new QPushButton(layoutWidget9);
        reflectionX->setObjectName(QString::fromUtf8("reflectionX"));

        horizontalLayout_5->addWidget(reflectionX);

        reflectionY = new QPushButton(layoutWidget9);
        reflectionY->setObjectName(QString::fromUtf8("reflectionY"));

        horizontalLayout_5->addWidget(reflectionY);

        reflectionO = new QPushButton(layoutWidget9);
        reflectionO->setObjectName(QString::fromUtf8("reflectionO"));

        horizontalLayout_5->addWidget(reflectionO);

        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(570, 530, 131, 20));
        label_20->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(460, 550, 351, 26));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        setCorner1 = new QPushButton(widget);
        setCorner1->setObjectName(QString::fromUtf8("setCorner1"));

        horizontalLayout_8->addWidget(setCorner1);

        setCorner2 = new QPushButton(widget);
        setCorner2->setObjectName(QString::fromUtf8("setCorner2"));

        horizontalLayout_8->addWidget(setCorner2);

        lineClippping = new QPushButton(widget);
        lineClippping->setObjectName(QString::fromUtf8("lineClippping"));

        horizontalLayout_8->addWidget(lineClippping);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        polygonClipping = new QPushButton(widget);
        polygonClipping->setObjectName(QString::fromUtf8("polygonClipping"));

        horizontalLayout_9->addWidget(polygonClipping);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 873, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "(450 X 450)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Time Taken", nullptr));
        set_point1->setText(QCoreApplication::translate("MainWindow", "Set point 1", nullptr));
        set_point2->setText(QCoreApplication::translate("MainWindow", "Set point 2", nullptr));
        DDALine->setText(QCoreApplication::translate("MainWindow", "DDA", nullptr));
        bresenhamLine->setText(QCoreApplication::translate("MainWindow", "Bresenham", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select Radius:", nullptr));
        setGridButton->setText(QCoreApplication::translate("MainWindow", "Set Grid", nullptr));
        showAxes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset Screen", nullptr));
        resetUtil->setText(QCoreApplication::translate("MainWindow", "Reset Plots", nullptr));
        time_taken->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "Animation Delay:", nullptr));
        polarCircle->setText(QCoreApplication::translate("MainWindow", "Polar", nullptr));
        bresenhamCircle->setText(QCoreApplication::translate("MainWindow", "Bresenham", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Select Major Axis:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Select Minor Axis:", nullptr));
        draw_ellipse_bresenham->setText(QCoreApplication::translate("MainWindow", "Bresenham Ellipse", nullptr));
        draw_ellipse_polar->setText(QCoreApplication::translate("MainWindow", "Polar Ellipse", nullptr));
        boundaryFill->setText(QCoreApplication::translate("MainWindow", "Boundary Fill", nullptr));
        floodFill->setText(QCoreApplication::translate("MainWindow", "Flood Fill", nullptr));
        scanLineFill->setText(QCoreApplication::translate("MainWindow", "ScanLine Fill", nullptr));
        setVertex->setText(QCoreApplication::translate("MainWindow", "Set Vertex", nullptr));
        clearVertex->setText(QCoreApplication::translate("MainWindow", "Clear Vertex", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Transformation", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Polygon Filling", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "x-translate", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "y-translate", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "angle", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "x-scale", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "y-scale", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "y-shear", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "x-shear", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Reflection", nullptr));
        translation->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        rotation->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        scaling->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        shearing->setText(QCoreApplication::translate("MainWindow", "Shearing", nullptr));
        reflection->setText(QCoreApplication::translate("MainWindow", "WRT Line", nullptr));
        reflectionX->setText(QCoreApplication::translate("MainWindow", "WRT X-Axis", nullptr));
        reflectionY->setText(QCoreApplication::translate("MainWindow", "WRT Y-Axis", nullptr));
        reflectionO->setText(QCoreApplication::translate("MainWindow", "WRT Origin", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Clipping", nullptr));
        setCorner1->setText(QCoreApplication::translate("MainWindow", "Set Corner 1", nullptr));
        setCorner2->setText(QCoreApplication::translate("MainWindow", "Set Corner 2", nullptr));
        lineClippping->setText(QCoreApplication::translate("MainWindow", "Line Clipping", nullptr));
        polygonClipping->setText(QCoreApplication::translate("MainWindow", "Polygon Clipping", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
