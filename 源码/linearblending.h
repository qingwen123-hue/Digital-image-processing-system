#ifndef LINEARBLENDING_H
#define LINEARBLENDING_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class LinearBlending;
}

class LinearBlending : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinearBlending(QWidget *parent = nullptr);
    ~LinearBlending();
    Mat OutImage,BlendImage;
    double alpha;
    QValidator *vali;
    void renovate();
    int flag;
    int width,height;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void SliderHander(int value);
    void on_SelectButton_clicked();
    void CameraHandle(int code);
    void on_SaveButton_clicked();

private:
    Ui::LinearBlending *ui;
};

#endif // LINEARBLENDING_H
