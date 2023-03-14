#include "edgedetection.h"
#include "ui_edgedetection.h"

EdgeDetection::EdgeDetection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EdgeDetection)
{
    ui->setupUi(this);
    Lalpha = 100;
    Halpha = 200;
    ui->HighSlider->setRange(0,255);
    ui->LowSlider->setRange(0,255);
    Hvali = new QIntValidator(0,255,this);
    Lvali = new QIntValidator(0,255,this);
    ui->HighEdit->setValidator(Hvali);
    ui->LowEdit->setValidator(Lvali);
    renovate();

    connect(ui->HighEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
    connect(ui->HighSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));

    connect(ui->LowEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
    connect(ui->LowSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));
}

EdgeDetection::~EdgeDetection()
{
    delete ui,Hvali,Lvali;
}

void EdgeDetection::ReceiveCode(int code)
{
    if(code == EDGEDETECTION)
    {
        OutImage.release();
        Lalpha = 100;
        Halpha = 200;
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();

    }

}

void EdgeDetection::renovate()
{

    Canny( mImage, OutImage, Lalpha, Halpha, 3);
    ui->HighEdit->setText(QString::number(Halpha));
    ui->HighSlider->setValue(Halpha);
    ui->LowEdit->setText(QString::number(Lalpha));
    ui->LowSlider->setValue(Lalpha);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);

}

void EdgeDetection::EditHander()
{
    Halpha = ui->HighEdit->text().toInt();
    Lalpha = ui->LowEdit->text().toInt();
    if(Halpha <= Lalpha)
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("高阈值不得小于低阈值"));
    }
    else
    {
        renovate();
    }

}

void EdgeDetection::SliderHander(int)
{
    Halpha = ui->HighSlider->value();
    Lalpha = ui->LowSlider->value();
    if(Halpha <= Lalpha)
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("高阈值不得小于低阈值"));
    }
    else
    {
        renovate();
    }
}


void EdgeDetection::on_SaveButton_clicked()
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

void EdgeDetection::CameraHandle(int code)
{
    if(code == EDGEDETECTION)
    {
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
    }

}

