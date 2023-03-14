/********************************************************************************
** Form generated from reading UI file 'linearblending.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARBLENDING_H
#define UI_LINEARBLENDING_H

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

class Ui_LinearBlending
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QSlider *alphaSlider;
    QPushButton *SaveButton;
    QPushButton *SelectButton;
    QLineEdit *alphaEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LinearBlending)
    {
        if (LinearBlending->objectName().isEmpty())
            LinearBlending->setObjectName(QString::fromUtf8("LinearBlending"));
        LinearBlending->resize(800, 600);
        centralwidget = new QWidget(LinearBlending);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        alphaSlider = new QSlider(centralwidget);
        alphaSlider->setObjectName(QString::fromUtf8("alphaSlider"));
        alphaSlider->setGeometry(QRect(560, 110, 231, 16));
        alphaSlider->setOrientation(Qt::Horizontal);
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(690, 10, 101, 41));
        SelectButton = new QPushButton(centralwidget);
        SelectButton->setObjectName(QString::fromUtf8("SelectButton"));
        SelectButton->setGeometry(QRect(550, 10, 131, 41));
        alphaEdit = new QLineEdit(centralwidget);
        alphaEdit->setObjectName(QString::fromUtf8("alphaEdit"));
        alphaEdit->setGeometry(QRect(660, 150, 131, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(610, 150, 51, 31));
        LinearBlending->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LinearBlending);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LinearBlending->setMenuBar(menubar);
        statusbar = new QStatusBar(LinearBlending);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LinearBlending->setStatusBar(statusbar);

        retranslateUi(LinearBlending);

        QMetaObject::connectSlotsByName(LinearBlending);
    } // setupUi

    void retranslateUi(QMainWindow *LinearBlending)
    {
        LinearBlending->setWindowTitle(QApplication::translate("LinearBlending", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("LinearBlending", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        SelectButton->setText(QApplication::translate("LinearBlending", "\351\200\211\346\213\251\346\267\267\345\220\210\345\233\276\347\211\207", nullptr));
        label->setText(QApplication::translate("LinearBlending", "alpha:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinearBlending: public Ui_LinearBlending {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARBLENDING_H
