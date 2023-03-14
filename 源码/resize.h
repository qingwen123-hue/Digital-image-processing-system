#ifndef RESIZE_H
#define RESIZE_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class ReSize;
}

class ReSize : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReSize(QWidget *parent = nullptr);
    ~ReSize();
    Mat OutImage;
    int width,height;
    QValidator *Wvali,*Hvali;
    void SizeChange(int w,int h);

private slots:
    void ReceiveCode(int code);
    void EditHander();
    void CameraHandle(int code);
    void on_SaveButton_clicked();

private:
    Ui::ReSize *ui;
};

#endif // RESIZE_H
