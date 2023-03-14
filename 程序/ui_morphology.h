/********************************************************************************
** Form generated from reading UI file 'morphology.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPHOLOGY_H
#define UI_MORPHOLOGY_H

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

class Ui_Morphology
{
public:
    QWidget *centralwidget;
    QLabel *img;
    QPushButton *SaveButton;
    QLineEdit *ElementEdit;
    QPushButton *ErodingButton;
    QPushButton *DilatingButton;
    QLabel *label;
    QPushButton *OpeningButton;
    QPushButton *ClosingButton;
    QPushButton *TopButton;
    QPushButton *BlackButton;
    QPushButton *GradientButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Morphology)
    {
        if (Morphology->objectName().isEmpty())
            Morphology->setObjectName(QString::fromUtf8("Morphology"));
        Morphology->resize(800, 600);
        centralwidget = new QWidget(Morphology);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(0, 0, 550, 550));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(680, 10, 111, 41));
        ElementEdit = new QLineEdit(centralwidget);
        ElementEdit->setObjectName(QString::fromUtf8("ElementEdit"));
        ElementEdit->setGeometry(QRect(670, 70, 113, 20));
        ErodingButton = new QPushButton(centralwidget);
        ErodingButton->setObjectName(QString::fromUtf8("ErodingButton"));
        ErodingButton->setGeometry(QRect(690, 100, 91, 41));
        DilatingButton = new QPushButton(centralwidget);
        DilatingButton->setObjectName(QString::fromUtf8("DilatingButton"));
        DilatingButton->setGeometry(QRect(580, 100, 91, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 70, 71, 21));
        OpeningButton = new QPushButton(centralwidget);
        OpeningButton->setObjectName(QString::fromUtf8("OpeningButton"));
        OpeningButton->setGeometry(QRect(580, 150, 91, 41));
        ClosingButton = new QPushButton(centralwidget);
        ClosingButton->setObjectName(QString::fromUtf8("ClosingButton"));
        ClosingButton->setGeometry(QRect(690, 150, 91, 41));
        TopButton = new QPushButton(centralwidget);
        TopButton->setObjectName(QString::fromUtf8("TopButton"));
        TopButton->setGeometry(QRect(580, 200, 91, 41));
        BlackButton = new QPushButton(centralwidget);
        BlackButton->setObjectName(QString::fromUtf8("BlackButton"));
        BlackButton->setGeometry(QRect(690, 200, 91, 41));
        GradientButton = new QPushButton(centralwidget);
        GradientButton->setObjectName(QString::fromUtf8("GradientButton"));
        GradientButton->setGeometry(QRect(580, 250, 91, 41));
        Morphology->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Morphology);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Morphology->setMenuBar(menubar);
        statusbar = new QStatusBar(Morphology);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Morphology->setStatusBar(statusbar);

        retranslateUi(Morphology);

        QMetaObject::connectSlotsByName(Morphology);
    } // setupUi

    void retranslateUi(QMainWindow *Morphology)
    {
        Morphology->setWindowTitle(QApplication::translate("Morphology", "MainWindow", nullptr));
        img->setText(QString());
        SaveButton->setText(QApplication::translate("Morphology", "\344\277\235\345\255\230", nullptr));
        ErodingButton->setText(QApplication::translate("Morphology", "\350\205\220\350\232\200", nullptr));
        DilatingButton->setText(QApplication::translate("Morphology", "\350\206\250\350\203\200", nullptr));
        label->setText(QApplication::translate("Morphology", "\346\223\215\344\275\234\345\217\202\346\225\260\357\274\232", nullptr));
        OpeningButton->setText(QApplication::translate("Morphology", "\345\274\200\350\277\220\347\256\227", nullptr));
        ClosingButton->setText(QApplication::translate("Morphology", "\351\227\255\350\277\220\347\256\227", nullptr));
        TopButton->setText(QApplication::translate("Morphology", "\351\241\266\345\270\275", nullptr));
        BlackButton->setText(QApplication::translate("Morphology", "\351\273\221\345\270\275", nullptr));
        GradientButton->setText(QApplication::translate("Morphology", "\345\275\242\346\200\201\346\242\257\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Morphology: public Ui_Morphology {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPHOLOGY_H
