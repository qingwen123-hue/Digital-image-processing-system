#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread.start();

    ui->listWidget->addItem("选择图像");
    ui->listWidget->addItem("图像大小改变");
    ui->listWidget->addItem("图像混合");
    ui->listWidget->addItem("亮度与对比度");
    ui->listWidget->addItem("灰度图");
    ui->listWidget->addItem("高斯滤波");
    ui->listWidget->addItem("边缘检测");
    ui->listWidget->addItem("形态学");
    ui->listWidget->addItem("频域");
    ui->listWidget->addItem("均衡化");
    ui->stackedWidget->setCurrentIndex(1);
    Nowcode = 0;
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(ClickItem(int)));

    ui->stackedWidget->addWidget(&resize);
    connect(this,SIGNAL(SendCode(int)),&resize,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&resize,SLOT(CameraHandle(int)));


    ui->stackedWidget->addWidget(&linearblending);
    connect(this,SIGNAL(SendCode(int)),&linearblending,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&linearblending,SLOT(CameraHandle(int)));

    //brightnesscontrast
    ui->stackedWidget->addWidget(&brightnesscontrast);
    connect(this,SIGNAL(SendCode(int)),&brightnesscontrast,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&brightnesscontrast,SLOT(CameraHandle(int)));

    //grayscle
    ui->stackedWidget->addWidget(&grayscle);
    connect(this,SIGNAL(SendCode(int)),&grayscle,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&grayscle,SLOT(CameraHandle(int)));

    //gaussianfiltering
    ui->stackedWidget->addWidget(&gaussianfiltering);
    connect(this,SIGNAL(SendCode(int)),&gaussianfiltering,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&gaussianfiltering,SLOT(CameraHandle(int)));

    //edgedetetion
    ui->stackedWidget->addWidget(&edgedetetion);
    connect(this,SIGNAL(SendCode(int)),&edgedetetion,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&edgedetetion,SLOT(CameraHandle(int)));

    //morphology
    ui->stackedWidget->addWidget(&morphology);
    connect(this,SIGNAL(SendCode(int)),&morphology,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&morphology,SLOT(CameraHandle(int)));

    //frequencydomain
    ui->stackedWidget->addWidget(&frequencydomain);
    connect(this,SIGNAL(SendCode(int)),&frequencydomain,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&frequencydomain,SLOT(CameraHandle(int)));

    //equalization
    ui->stackedWidget->addWidget(&equalization);
    connect(this,SIGNAL(SendCode(int)),&equalization,SLOT(ReceiveCode(int)));
    connect(&thread,SIGNAL(CameraCode(int)),&equalization,SLOT(CameraHandle(int)));


    connect(&thread,SIGNAL(CameraCode(int)),this,SLOT(CameraHandle(int)));


}

MainWindow::~MainWindow()
{
    thread.exit();
    delete ui;
}


void MainWindow::ClickItem(int i)
{
    //qDebug()<<i;
    if(!MajorImage.empty())
    {
        ui->stackedWidget->setCurrentIndex(i+1);
        Nowcode = i;
        emit SendCode(i);
    }
}


void MainWindow::on_seletButton_clicked()
{
    QString dir = QFileDialog::getOpenFileName(
                        this,
                        tr("选择文件"),
                        "",
                        "All files(*.*)");
    MajorImage = imread(dir.toLatin1().data(),-1);
    //qDebug() << MajorImage.type();
    QPixmap pixmap = MatToPixmap(MajorImage);
    //emit SendMat(MajorImage);
    ui->img->setPixmap(pixmap);
}






void MainWindow::on_CameraButton_clicked()
{
    if(CameraFlag == 0)
    {
       CameraFlag = 1;
       ui->CameraButton->setText("关闭摄像头");
       ui->seletButton->setEnabled(false);

    }
    else
    {
        CameraFlag = 0;
        ui->CameraButton->setText("打开摄像头");
        ui->seletButton->setEnabled(true);
    }
}

void MainWindow::CameraHandle(int code)
{
    if(code == 0)
    {
        QPixmap pixmap = MatToPixmap(MajorImage);
        ui->img->setPixmap(pixmap);
    }
}

