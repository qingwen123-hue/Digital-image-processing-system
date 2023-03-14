#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class EdgeDetection;
}

class EdgeDetection : public QMainWindow
{
    Q_OBJECT

public:
    explicit EdgeDetection(QWidget *parent = nullptr);
    ~EdgeDetection();
    void renovate();
    Mat OutImage,mImage,GraImage;
    int Halpha,Lalpha;
    QValidator *Hvali,*Lvali;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void SliderHander(int value);
    void CameraHandle(int code);
    void on_SaveButton_clicked();

private:
    Ui::EdgeDetection *ui;
};

#endif // EDGEDETECTION_H
