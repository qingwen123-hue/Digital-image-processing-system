/********************************************************************************
** Form generated from reading UI file 'equalization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUALIZATION_H
#define UI_EQUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equalization
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Equalization)
    {
        if (Equalization->objectName().isEmpty())
            Equalization->setObjectName(QString::fromUtf8("Equalization"));
        Equalization->resize(800, 600);
        centralwidget = new QWidget(Equalization);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(680, 10, 101, 41));
        Equalization->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Equalization);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Equalization->setMenuBar(menubar);
        statusbar = new QStatusBar(Equalization);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Equalization->setStatusBar(statusbar);

        retranslateUi(Equalization);

        QMetaObject::connectSlotsByName(Equalization);
    } // setupUi

    void retranslateUi(QMainWindow *Equalization)
    {
        Equalization->setWindowTitle(QApplication::translate("Equalization", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("Equalization", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Equalization: public Ui_Equalization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUALIZATION_H
