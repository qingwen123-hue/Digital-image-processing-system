#ifndef EQUALIZATION_H
#define EQUALIZATION_H

#include <QMainWindow>
#include "generalfunction.h"
namespace Ui {
class Equalization;
}

class Equalization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Equalization(QWidget *parent = nullptr);
    ~Equalization();
    Mat OutImage;
    vector<Mat> BGRArray;
private slots:
    void ReceiveCode(int code);
    void on_SaveButton_clicked();
    void CameraHandle(int code);
private:
    Ui::Equalization *ui;
};

#endif // EQUALIZATION_H
