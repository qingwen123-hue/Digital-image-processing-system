/********************************************************************************
** Form generated from reading UI file 'brightnesscontrast.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTNESSCONTRAST_H
#define UI_BRIGHTNESSCONTRAST_H

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

class Ui_BrightnessContrast
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *BrightEdit;
    QLineEdit *ContrastEdit;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BrightnessContrast)
    {
        if (BrightnessContrast->objectName().isEmpty())
            BrightnessContrast->setObjectName(QString::fromUtf8("BrightnessContrast"));
        BrightnessContrast->resize(800, 600);
        centralwidget = new QWidget(BrightnessContrast);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(650, 10, 111, 41));
        BrightEdit = new QLineEdit(centralwidget);
        BrightEdit->setObjectName(QString::fromUtf8("BrightEdit"));
        BrightEdit->setGeometry(QRect(640, 70, 131, 31));
        ContrastEdit = new QLineEdit(centralwidget);
        ContrastEdit->setObjectName(QString::fromUtf8("ContrastEdit"));
        ContrastEdit->setGeometry(QRect(640, 120, 131, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 70, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 120, 71, 31));
        BrightnessContrast->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BrightnessContrast);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        BrightnessContrast->setMenuBar(menubar);
        statusbar = new QStatusBar(BrightnessContrast);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BrightnessContrast->setStatusBar(statusbar);

        retranslateUi(BrightnessContrast);

        QMetaObject::connectSlotsByName(BrightnessContrast);
    } // setupUi

    void retranslateUi(QMainWindow *BrightnessContrast)
    {
        BrightnessContrast->setWindowTitle(QApplication::translate("BrightnessContrast", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("BrightnessContrast", "\344\277\235\345\255\230", nullptr));
        label_2->setText(QApplication::translate("BrightnessContrast", "\344\272\256\345\272\246\345\217\202\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("BrightnessContrast", "\345\257\271\346\257\224\345\272\246\345\217\202\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrightnessContrast: public Ui_BrightnessContrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTNESSCONTRAST_H
