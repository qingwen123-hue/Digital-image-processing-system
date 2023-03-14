#ifndef BRIGHTNESSCONTRAST_H
#define BRIGHTNESSCONTRAST_H

#include <QMainWindow>
#include "generalfunction.h"

namespace Ui {
class BrightnessContrast;
}

class BrightnessContrast : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrightnessContrast(QWidget *parent = nullptr);
    ~BrightnessContrast();
    Mat OutImage;
    double alpha,beta;
    QValidator *Bvali,*Cvali;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void on_SaveButton_clicked();
    void CameraHandle(int code);
private:
    Ui::BrightnessContrast *ui;
};

#endif // BRIGHTNESSCONTRAST_H
