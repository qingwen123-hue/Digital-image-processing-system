/********************************************************************************
** Form generated from reading UI file 'generalinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALINTERFACE_H
#define UI_GENERALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralInterface
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QPushButton *CameraButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GeneralInterface)
    {
        if (GeneralInterface->objectName().isEmpty())
            GeneralInterface->setObjectName(QString::fromUtf8("GeneralInterface"));
        GeneralInterface->resize(792, 600);
        centralwidget = new QWidget(GeneralInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(620, 10, 121, 41));
        CameraButton = new QPushButton(centralwidget);
        CameraButton->setObjectName(QString::fromUtf8("CameraButton"));
        CameraButton->setGeometry(QRect(620, 70, 121, 41));
        GeneralInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GeneralInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 792, 21));
        GeneralInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(GeneralInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GeneralInterface->setStatusBar(statusbar);

        retranslateUi(GeneralInterface);

        QMetaObject::connectSlotsByName(GeneralInterface);
    } // setupUi

    void retranslateUi(QMainWindow *GeneralInterface)
    {
        GeneralInterface->setWindowTitle(QApplication::translate("GeneralInterface", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("GeneralInterface", "\344\277\235\345\255\230", nullptr));
        CameraButton->setText(QApplication::translate("GeneralInterface", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralInterface: public Ui_GeneralInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALINTERFACE_H
