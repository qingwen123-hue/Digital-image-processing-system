/********************************************************************************
** Form generated from reading UI file 'gaussianblur.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSSIANBLUR_H
#define UI_GAUSSIANBLUR_H

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

class Ui_GaussianBlur
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GaussianBlur)
    {
        if (GaussianBlur->objectName().isEmpty())
            GaussianBlur->setObjectName(QString::fromUtf8("GaussianBlur"));
        GaussianBlur->resize(800, 600);
        centralwidget = new QWidget(GaussianBlur);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(660, 10, 121, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(700, 90, 71, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(630, 80, 71, 31));
        GaussianBlur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GaussianBlur);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        GaussianBlur->setMenuBar(menubar);
        statusbar = new QStatusBar(GaussianBlur);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GaussianBlur->setStatusBar(statusbar);

        retranslateUi(GaussianBlur);

        QMetaObject::connectSlotsByName(GaussianBlur);
    } // setupUi

    void retranslateUi(QMainWindow *GaussianBlur)
    {
        GaussianBlur->setWindowTitle(QApplication::translate("GaussianBlur", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("GaussianBlur", "\344\277\235\345\255\230", nullptr));
        label->setText(QApplication::translate("GaussianBlur", "\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaussianBlur: public Ui_GaussianBlur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSSIANBLUR_H
