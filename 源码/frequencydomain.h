#ifndef FREQUENCYDOMAIN_H
#define FREQUENCYDOMAIN_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class FrequencyDomain;
}

class FrequencyDomain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrequencyDomain(QWidget *parent = nullptr);
    ~FrequencyDomain();
    FftOperation fftOpe;
    Mat OutImage,Spectrogram,TransformImg,mImage,GrayImage;
    int Radius,flag;
    QValidator *vali;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void on_HighButton_clicked();

    void on_LowButton_clicked();

    void on_SpectrogramButton_clicked();

    void on_pushButton_clicked();
    void CameraHandle(int code);
private:
    Ui::FrequencyDomain *ui;
};

#endif // FREQUENCYDOMAIN_H
