#include "gaussianfiltering.h"
#include "ui_gaussianfiltering.h"

GaussianFiltering::GaussianFiltering(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GaussianFiltering)
{
    ui->setupUi(this);
    alpha = 3;
    vali = new QIntValidator(1,100,this);
    ui->lineEdit->setValidator(vali);
    ui->lineEdit->setText(QString::number(3));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
}

GaussianFiltering::~GaussianFiltering()
{
    delete ui,vali;
}

void GaussianFiltering::ReceiveCode(int code)
{
    if(code == GAUSSIANFILTERING)
    {
        OutImage.release();
        //MajorImage.convertTo(OutImage, -1, alpha, beta);
        GaussianBlur(MajorImage,OutImage,Size(3,3),0,0);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
}

void GaussianFiltering::EditHander()
{
    alpha = ui->lineEdit->text().toInt();
    if(alpha%2 == 1)
    {
        GaussianBlur(MajorImage,OutImage,Size(alpha,alpha),0,0);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
    else
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("核大小应为奇数"));
    }

}


void GaussianFiltering::on_SaveButton_clicked()
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

void GaussianFiltering::CameraHandle(int code)
{
    if(code == GAUSSIANFILTERING)
    {
        //OutImage.release();
        //MajorImage.convertTo(OutImage, -1, alpha, beta);
        GaussianBlur(MajorImage,OutImage,Size(alpha,alpha),0,0);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
}

