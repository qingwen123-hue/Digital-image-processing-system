#include "equalization.h"
#include "ui_equalization.h"

Equalization::Equalization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Equalization)
{
    ui->setupUi(this);
}

Equalization::~Equalization()
{
    delete ui;
}

void Equalization::ReceiveCode(int code)
{
    if(code == EQUALIZATION)
    {
        OutImage.release();
//        qDebug() << MajorImage.type();
//        qDebug() <<CV_8UC1;
//        qDebug() <<CV_8UC3;
        if(MajorImage.type() == CV_8UC1)
        {

            equalizeHist( MajorImage, OutImage );
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);

        }
        else if(MajorImage.type() == CV_8UC3)
        {
            split(MajorImage,BGRArray);
            equalizeHist( BGRArray[0], BGRArray[0] );
            equalizeHist( BGRArray[1], BGRArray[1] );
            equalizeHist( BGRArray[2], BGRArray[2] );
            merge(BGRArray,OutImage);
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);
        }
    }
}

void Equalization::on_SaveButton_clicked()
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

void Equalization::CameraHandle(int code)
{
    if(code == EQUALIZATION)
    {
        split(MajorImage,BGRArray);
        equalizeHist( BGRArray[0], BGRArray[0] );
        equalizeHist( BGRArray[1], BGRArray[1] );
        equalizeHist( BGRArray[2], BGRArray[2] );
        merge(BGRArray,OutImage);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);

    }
}

