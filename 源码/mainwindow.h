#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "generalfunction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //GeneralInterface aaa;
    LinearBlending linearblending;
    ReSize resize;
    BrightnessContrast brightnesscontrast;
    Grayscale grayscle;
    GaussianFiltering gaussianfiltering;
    EdgeDetection edgedetetion;
    Morphology morphology;
    FrequencyDomain frequencydomain;
    Equalization equalization;

    CameraTThread thread;
    VideoCapture cap;

private slots:
    void ClickItem(int i);
    void CameraHandle(int code);


signals:
    void SendCode(int code);

private slots:

    void on_seletButton_clicked();


    void on_CameraButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
