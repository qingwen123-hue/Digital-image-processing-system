#ifndef GAUSSIANFILTERING_H
#define GAUSSIANFILTERING_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class GaussianFiltering;
}

class GaussianFiltering : public QMainWindow
{
    Q_OBJECT

public:
    explicit GaussianFiltering(QWidget *parent = nullptr);
    ~GaussianFiltering();
    Mat OutImage;
    QValidator *vali;
    int alpha;
private slots:
    void ReceiveCode(int code);
    void EditHander();
    void CameraHandle(int code);
    void on_SaveButton_clicked();

private:
    Ui::GaussianFiltering *ui;
};

#endif // GAUSSIANFILTERING_H
