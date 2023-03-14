#include "frequencydomain.h"
#include "ui_frequencydomain.h"

FrequencyDomain::FrequencyDomain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrequencyDomain)
{
    ui->setupUi(this);
    Radius = 50;
    flag = 3;
    vali = new QIntValidator(0,100,this);
    ui->RadiusEdit->setValidator(vali);
    ui->RadiusEdit->setText(QString::number(Radius));
    connect(ui->RadiusEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
}

FrequencyDomain::~FrequencyDomain()
{
    delete ui,vali;
}

void FrequencyDomain::ReceiveCode(int code)
{
    if(code == FREQUENCYDOMAIN)
    {
        cvtColor(MajorImage, GrayImage, COLOR_BGR2GRAY);
        fftOpe.ImgFft(GrayImage, &Spectrogram, &TransformImg);
        Spectrogram.convertTo(Spectrogram,CV_8U,255.0);
        OutImage = Spectrogram.clone();
        QPixmap pixmap = MatToPixmap(Spectrogram);
        ui->img->setPixmap(pixmap);
    }
}

void FrequencyDomain::EditHander()
{
    Radius= ui->RadiusEdit->text().toInt();
}

void FrequencyDomain::on_HighButton_clicked()
{
    //qDebug()<<1;
    fftOpe.GaussianFilteringHigh(TransformImg, &mImage, Radius);
    fftOpe.ImgIfft(mImage, &OutImage);
    OutImage.convertTo(OutImage,CV_8U,255.0);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
    flag = 1;
}


void FrequencyDomain::on_LowButton_clicked()
{
    //qDebug()<<2;
    fftOpe.GaussianFilteringLow(TransformImg, &mImage, Radius);
    fftOpe.ImgIfft(mImage, &OutImage);
    OutImage.convertTo(OutImage,CV_8U,255.0);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
    flag = 2;
}


void FrequencyDomain::on_SpectrogramButton_clicked()
{
    //qDebug()<<3;

    QPixmap pixmap = MatToPixmap(Spectrogram);
    //qDebug()<<Spectrogram.type();
    ui->img->setPixmap(pixmap);
    flag = 3;
}


void FrequencyDomain::on_pushButton_clicked()
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

void FrequencyDomain::CameraHandle(int code)
{
    if(code == FREQUENCYDOMAIN)
    {
        if(flag == 1)
        {
            cvtColor(MajorImage, GrayImage, COLOR_BGR2GRAY);
            fftOpe.ImgFft(GrayImage, &Spectrogram, &TransformImg);
//            Spectrogram.convertTo(Spectrogram,CV_8U,255.0);
//            OutImage = Spectrogram.clone();
            fftOpe.GaussianFilteringHigh(TransformImg, &mImage, Radius);
            fftOpe.ImgIfft(mImage, &OutImage);
            OutImage.convertTo(OutImage,CV_8U,255.0);
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);
        }
        else if(flag == 2)
        {
            cvtColor(MajorImage, GrayImage, COLOR_BGR2GRAY);
            fftOpe.ImgFft(GrayImage, &Spectrogram, &TransformImg);
//            Spectrogram.convertTo(Spectrogram,CV_8U,255.0);
//            OutImage = Spectrogram.clone();
            fftOpe.GaussianFilteringLow(TransformImg, &mImage, Radius);
            fftOpe.ImgIfft(mImage, &OutImage);
            OutImage.convertTo(OutImage,CV_8U,255.0);
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);
        }
        else if(flag == 3)
        {
            cvtColor(MajorImage, GrayImage, COLOR_BGR2GRAY);
            fftOpe.ImgFft(GrayImage, &Spectrogram, &TransformImg);
            Spectrogram.convertTo(Spectrogram,CV_8U,255.0);
            OutImage = Spectrogram.clone();
//            fftOpe.GaussianFilteringLow(TransformImg, &mImage, Radius);
//            fftOpe.ImgIfft(mImage, &OutImage);
//            OutImage.convertTo(OutImage,CV_8U,255.0);
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);
        }
    }
}

