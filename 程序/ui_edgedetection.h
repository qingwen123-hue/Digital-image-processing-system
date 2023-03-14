/********************************************************************************
** Form generated from reading UI file 'edgedetection.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGEDETECTION_H
#define UI_EDGEDETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EdgeDetection
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *HighEdit;
    QSlider *HighSlider;
    QLabel *label_2;
    QSlider *LowSlider;
    QLabel *label_3;
    QLineEdit *LowEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EdgeDetection)
    {
        if (EdgeDetection->objectName().isEmpty())
            EdgeDetection->setObjectName(QString::fromUtf8("EdgeDetection"));
        EdgeDetection->resize(800, 600);
        centralwidget = new QWidget(EdgeDetection);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(660, 10, 111, 41));
        HighEdit = new QLineEdit(centralwidget);
        HighEdit->setObjectName(QString::fromUtf8("HighEdit"));
        HighEdit->setGeometry(QRect(672, 110, 101, 21));
        HighSlider = new QSlider(centralwidget);
        HighSlider->setObjectName(QString::fromUtf8("HighSlider"));
        HighSlider->setGeometry(QRect(610, 80, 160, 16));
        HighSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 110, 61, 21));
        LowSlider = new QSlider(centralwidget);
        LowSlider->setObjectName(QString::fromUtf8("LowSlider"));
        LowSlider->setGeometry(QRect(608, 140, 160, 16));
        LowSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(598, 170, 61, 21));
        LowEdit = new QLineEdit(centralwidget);
        LowEdit->setObjectName(QString::fromUtf8("LowEdit"));
        LowEdit->setGeometry(QRect(670, 170, 101, 21));
        EdgeDetection->setCentralWidget(centralwidget);
        HighEdit->raise();
        img->raise();
        SaveButton->raise();
        HighSlider->raise();
        label_2->raise();
        LowSlider->raise();
        label_3->raise();
        LowEdit->raise();
        menubar = new QMenuBar(EdgeDetection);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        EdgeDetection->setMenuBar(menubar);
        statusbar = new QStatusBar(EdgeDetection);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EdgeDetection->setStatusBar(statusbar);

        retranslateUi(EdgeDetection);

        QMetaObject::connectSlotsByName(EdgeDetection);
    } // setupUi

    void retranslateUi(QMainWindow *EdgeDetection)
    {
        EdgeDetection->setWindowTitle(QApplication::translate("EdgeDetection", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("EdgeDetection", "\344\277\235\345\255\230", nullptr));
        label_2->setText(QApplication::translate("EdgeDetection", "\351\253\230\351\230\210\345\200\274\357\274\232", nullptr));
        label_3->setText(QApplication::translate("EdgeDetection", "\344\275\216\351\230\210\345\200\274:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EdgeDetection: public Ui_EdgeDetection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTION_H
