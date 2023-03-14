#include "linearblending.h"
#include "ui_linearblending.h"

LinearBlending::LinearBlending(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LinearBlending)
{
    ui->setupUi(this);
    vali = new QDoubleValidator(0.0,1.0,4,this);
    ui->alphaEdit->setValidator(vali);
    alpha = 0.5;
    flag = 0;
    ui->alphaSlider->setRange(0,100);
    ui->alphaSlider->setValue(alpha*100);
    ui->alphaEdit->setText(QString::number(alpha));
    connect(ui->alphaEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
    //valueChanged()
    connect(ui->alphaSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));

}

LinearBlending::~LinearBlending()
{
    delete ui,vali;
}

void LinearBlending::ReceiveCode(int code)
{
    if(code == LINEARBLENDING)
    {
        OutImage.release();
        //OutImage = MajorImage;
        QPixmap pixmap = MatToPixmap(MajorImage);
        ui->img->setPixmap(pixmap);
        width = MajorImage.cols;
        height = MajorImage.rows;
    }
}

void LinearBlending::on_SelectButton_clicked()
{
    QString dir = QFileDialog::getOpenFileName(
                        this,
                        tr("选择文件"),
                        "",
                        "All files(*.*)");
    BlendImage = imread(dir.toLatin1().data());
    cv::resize(BlendImage, BlendImage, Size(width, height), INTER_LINEAR);
    addWeighted(MajorImage,alpha,BlendImage,1.0-alpha,0.0,OutImage);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
    flag = 1;
}

void LinearBlending::EditHander()
{
    alpha = ui->alphaEdit->text().toDouble();
    renovate();
}

void LinearBlending::SliderHander(int value)
{
    alpha = value/100.0;
    renovate();
}

void LinearBlending::renovate()
{
    ui->alphaSlider->setValue(alpha*100);
    ui->alphaEdit->setText(QString::number(alpha));
    addWeighted(MajorImage,alpha,BlendImage,1.0-alpha,0.0,OutImage);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void LinearBlending::on_SaveButton_clicked()
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

void LinearBlending::CameraHandle(int code)
{
    if(code == LINEARBLENDING)
    {
        if(flag == 1)
        {
            renovate();
        }

    }
}

