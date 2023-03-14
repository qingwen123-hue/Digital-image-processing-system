#include "generalinterface.h"
#include "ui_generalinterface.h"

GeneralInterface::GeneralInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GeneralInterface)
{
    ui->setupUi(this);
    setWindowTitle("GeneralInterface");
    CameraFlag = 0;
}

GeneralInterface::~GeneralInterface()
{
    delete ui;
}

void GeneralInterface::ReceiveCode(int code)
{
    if(code == GENERALINTERFACE)
    {
        OutImage.release();
        OutImage = MajorImage;
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
//    image = src;
//    QPixmap pixmap = MatToPixmap(image);
//    ui->img->setPixmap(pixmap);
}

void GeneralInterface::on_SaveButton_clicked()
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




void GeneralInterface::CameraHandle(int code)
{
    if(code == GENERALINTERFACE)
    {
        QPixmap pixmap = MatToPixmap(MajorImage);
        ui->img->setPixmap(pixmap);
    }
}



