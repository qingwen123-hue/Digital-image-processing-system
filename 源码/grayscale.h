#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class Grayscale;
}

class Grayscale : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grayscale(QWidget *parent = nullptr);
    ~Grayscale();
    Mat OutImage,GraImage;
    QValidator *vali;
    int alpha;
    int Otus(Mat img);
    int flag;
private slots:
    void ReceiveCode(int code);
    void change(int state);
    void EditHander();
    void SliderHander(int value);
    void on_SaveButton_clicked();
    void CameraHandle(int code);
    void on_OTSUButton_clicked();

private:
    Ui::Grayscale *ui;
};

#endif // GRAYSCALE_H
