/********************************************************************************
** Form generated from reading UI file 'frequencydomain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCYDOMAIN_H
#define UI_FREQUENCYDOMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrequencyDomain
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *pushButton;
    QRadioButton *HighButton;
    QLineEdit *RadiusEdit;
    QLabel *label_2;
    QRadioButton *LowButton;
    QRadioButton *SpectrogramButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FrequencyDomain)
    {
        if (FrequencyDomain->objectName().isEmpty())
            FrequencyDomain->setObjectName(QString::fromUtf8("FrequencyDomain"));
        FrequencyDomain->resize(800, 600);
        centralwidget = new QWidget(FrequencyDomain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(690, 10, 91, 41));
        HighButton = new QRadioButton(centralwidget);
        HighButton->setObjectName(QString::fromUtf8("HighButton"));
        HighButton->setGeometry(QRect(670, 110, 91, 18));
        RadiusEdit = new QLineEdit(centralwidget);
        RadiusEdit->setObjectName(QString::fromUtf8("RadiusEdit"));
        RadiusEdit->setGeometry(QRect(670, 60, 113, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 60, 71, 21));
        LowButton = new QRadioButton(centralwidget);
        LowButton->setObjectName(QString::fromUtf8("LowButton"));
        LowButton->setGeometry(QRect(670, 140, 91, 18));
        SpectrogramButton = new QRadioButton(centralwidget);
        SpectrogramButton->setObjectName(QString::fromUtf8("SpectrogramButton"));
        SpectrogramButton->setGeometry(QRect(670, 170, 91, 18));
        SpectrogramButton->setChecked(true);
        FrequencyDomain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FrequencyDomain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        FrequencyDomain->setMenuBar(menubar);
        statusbar = new QStatusBar(FrequencyDomain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FrequencyDomain->setStatusBar(statusbar);

        retranslateUi(FrequencyDomain);

        QMetaObject::connectSlotsByName(FrequencyDomain);
    } // setupUi

    void retranslateUi(QMainWindow *FrequencyDomain)
    {
        FrequencyDomain->setWindowTitle(QApplication::translate("FrequencyDomain", "MainWindow", nullptr));
        img->setText(QString());
        pushButton->setText(QApplication::translate("FrequencyDomain", "\344\277\235\345\255\230", nullptr));
        HighButton->setText(QApplication::translate("FrequencyDomain", "\351\253\230\351\200\232", nullptr));
        label_2->setText(QApplication::translate("FrequencyDomain", "\346\273\244\346\263\242\345\215\212\345\276\204\357\274\232", nullptr));
        LowButton->setText(QApplication::translate("FrequencyDomain", "\344\275\216\351\200\232", nullptr));
        SpectrogramButton->setText(QApplication::translate("FrequencyDomain", "\351\242\221\350\260\261\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrequencyDomain: public Ui_FrequencyDomain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCYDOMAIN_H
