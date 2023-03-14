/********************************************************************************
** Form generated from reading UI file 'grayscale.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAYSCALE_H
#define UI_GRAYSCALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Grayscale
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *OTSUButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Grayscale)
    {
        if (Grayscale->objectName().isEmpty())
            Grayscale->setObjectName(QString::fromUtf8("Grayscale"));
        Grayscale->resize(800, 600);
        centralwidget = new QWidget(Grayscale);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(670, 10, 111, 51));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(680, 80, 91, 31));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(560, 120, 221, 21));
        horizontalSlider->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(630, 150, 141, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 150, 71, 31));
        OTSUButton = new QPushButton(centralwidget);
        OTSUButton->setObjectName(QString::fromUtf8("OTSUButton"));
        OTSUButton->setGeometry(QRect(640, 210, 111, 51));
        Grayscale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Grayscale);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Grayscale->setMenuBar(menubar);
        statusbar = new QStatusBar(Grayscale);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Grayscale->setStatusBar(statusbar);

        retranslateUi(Grayscale);

        QMetaObject::connectSlotsByName(Grayscale);
    } // setupUi

    void retranslateUi(QMainWindow *Grayscale)
    {
        Grayscale->setWindowTitle(QApplication::translate("Grayscale", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("Grayscale", "\344\277\235\345\255\230", nullptr));
        checkBox->setText(QApplication::translate("Grayscale", "\344\272\214\345\200\274\345\214\226", nullptr));
        label->setText(QApplication::translate("Grayscale", "\351\230\210\345\200\274\357\274\232", nullptr));
        OTSUButton->setText(QApplication::translate("Grayscale", "OTSU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Grayscale: public Ui_Grayscale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAYSCALE_H
