/********************************************************************************
** Form generated from reading UI file 'general_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERAL_INTERFACE_H
#define UI_GENERAL_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_General_Interface
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *General_Interface)
    {
        if (General_Interface->objectName().isEmpty())
            General_Interface->setObjectName(QString::fromUtf8("General_Interface"));
        General_Interface->resize(800, 600);
        centralwidget = new QWidget(General_Interface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(10, 10, 551, 541));
        General_Interface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(General_Interface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        General_Interface->setMenuBar(menubar);
        statusbar = new QStatusBar(General_Interface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        General_Interface->setStatusBar(statusbar);

        retranslateUi(General_Interface);

        QMetaObject::connectSlotsByName(General_Interface);
    } // setupUi

    void retranslateUi(QMainWindow *General_Interface)
    {
        General_Interface->setWindowTitle(QApplication::translate("General_Interface", "MainWindow", nullptr));
        img->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class General_Interface: public Ui_General_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_INTERFACE_H
