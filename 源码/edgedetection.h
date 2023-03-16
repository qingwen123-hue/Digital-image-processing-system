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
    int Halpha,Lalpha,Houghalpha;
    QValidator *Hvali,*Lvali,*Houghvali;
    int flag;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void SliderHander(int value);
    void CameraHandle(int code);
    void on_SaveButton_clicked();

    void on_HoughLineBox_stateChanged(int arg1);

    void on_HoughCircleBox_stateChanged(int arg1);


private:
    Ui::EdgeDetection *ui;
};

#endif // EDGEDETECTION_H
