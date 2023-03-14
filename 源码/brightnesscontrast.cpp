#include "brightnesscontrast.h"
#include "ui_brightnesscontrast.h"

BrightnessContrast::BrightnessContrast(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BrightnessContrast)
{
    ui->setupUi(this);
    alpha = 1;//对比度
    beta = 0;//亮比度
    Bvali = new QDoubleValidator(-255.0,255.0,4,this);
    Cvali = new QDoubleValidator(0,10.0,4,this);
    ui->BrightEdit->setValidator(Bvali);
    ui->ContrastEdit->setValidator(Cvali);
    ui->BrightEdit->setText(QString::number(beta));
    ui->ContrastEdit->setText(QString::number(alpha));
    connect(ui->BrightEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
    connect(ui->ContrastEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
}

BrightnessContrast::~BrightnessContrast()
{
    delete ui,Bvali,Cvali;
}

void BrightnessContrast::ReceiveCode(int code)
{
    if(code == BRIGHTNESSCONTRAST)
    {
        OutImage.release();
        MajorImage.convertTo(OutImage, -1, alpha, beta);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
}

void BrightnessContrast::EditHander()
{
    beta = ui->BrightEdit->text().toDouble();
    alpha = ui->ContrastEdit->text().toDouble();
    MajorImage.convertTo(OutImage, -1, alpha, beta);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void BrightnessContrast::on_SaveButton_clicked()
{
    if(!OutImage.empty())
    {
        QString dir = QFileDialog::getSaveFileName(
                            this,
                            tr("保存文件"),
                            "",
                            "Images (*.png *.xpm *.jpg *.tif)");
        QImage img = MatToImage(OutImage);
        img.save(dir);
    }
}

void BrightnessContrast::CameraHandle(int code)
{
    if(code == BRIGHTNESSCONTRAST)
    {
        //OutImage.release();
        MajorImage.convertTo(OutImage, -1, alpha, beta);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
}

