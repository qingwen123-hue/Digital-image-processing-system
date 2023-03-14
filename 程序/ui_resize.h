/********************************************************************************
** Form generated from reading UI file 'resize.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZE_H
#define UI_RESIZE_H

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

class Ui_ReSize
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *widthEdit;
    QLineEdit *heightEdit;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ReSize)
    {
        if (ReSize->objectName().isEmpty())
            ReSize->setObjectName(QString::fromUtf8("ReSize"));
        ReSize->resize(800, 600);
        centralwidget = new QWidget(ReSize);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(660, 10, 121, 51));
        widthEdit = new QLineEdit(centralwidget);
        widthEdit->setObjectName(QString::fromUtf8("widthEdit"));
        widthEdit->setGeometry(QRect(660, 80, 101, 31));
        heightEdit = new QLineEdit(centralwidget);
        heightEdit->setObjectName(QString::fromUtf8("heightEdit"));
        heightEdit->setGeometry(QRect(660, 120, 101, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 80, 41, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 120, 41, 31));
        ReSize->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ReSize);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ReSize->setMenuBar(menubar);
        statusbar = new QStatusBar(ReSize);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ReSize->setStatusBar(statusbar);

        retranslateUi(ReSize);

        QMetaObject::connectSlotsByName(ReSize);
    } // setupUi

    void retranslateUi(QMainWindow *ReSize)
    {
        ReSize->setWindowTitle(QApplication::translate("ReSize", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("ReSize", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        label->setText(QApplication::translate("ReSize", "\345\256\275\345\272\246\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ReSize", "\351\253\230\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReSize: public Ui_ReSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZE_H
