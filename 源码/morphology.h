#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include <QMainWindow>
#include <generalfunction.h>
namespace Ui {
class Morphology;
}

class Morphology : public QMainWindow
{
    Q_OBJECT

public:
    explicit Morphology(QWidget *parent = nullptr);
    ~Morphology();
    Mat OutImage;
    int Erod;
    QValidator *Evali;
    void Handle(int code);
    int flag,size;
private slots:
    void ReceiveCode(int code);
    void on_ErodingButton_clicked();

    void on_DilatingButton_clicked();

    void on_SaveButton_clicked();

    void on_OpeningButton_clicked();

    void on_ClosingButton_clicked();

    void on_TopButton_clicked();

    void on_BlackButton_clicked();

    void on_GradientButton_clicked();

    void CameraHandle(int code);
    void EditHander();
private:
    Ui::Morphology *ui;
};

#endif // MORPHOLOGY_H
