/********************************************************************************
** Form generated from reading UI file 'gaussianfiltering.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSIANFILTERING_H
#define UI_GAUSSIANFILTERING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GaussianFiltering
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GaussianFiltering)
    {
        if (GaussianFiltering->objectName().isEmpty())
            GaussianFiltering->setObjectName(QString::fromUtf8("GaussianFiltering"));
        GaussianFiltering->resize(800, 600);
        centralwidget = new QWidget(GaussianFiltering);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(660, 20, 121, 51));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(700, 90, 81, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 90, 71, 21));
        GaussianFiltering->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GaussianFiltering);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        GaussianFiltering->setMenuBar(menubar);
        statusbar = new QStatusBar(GaussianFiltering);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GaussianFiltering->setStatusBar(statusbar);

        retranslateUi(GaussianFiltering);

        QMetaObject::connectSlotsByName(GaussianFiltering);
    } // setupUi

    void retranslateUi(QMainWindow *GaussianFiltering)
    {
        GaussianFiltering->setWindowTitle(QApplication::translate("GaussianFiltering", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("GaussianFiltering", "\344\277\235\345\255\230", nullptr));
        label->setText(QApplication::translate("GaussianFiltering", "\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaussianFiltering: public Ui_GaussianFiltering {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSIANFILTERING_H
