#include "edgedetection.h"
#include "ui_edgedetection.h"

EdgeDetection::EdgeDetection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EdgeDetection)
{
    ui->setupUi(this);
    flag =0 ;
    Lalpha = 100;
    Halpha = 200;
    Houghalpha = 50;
    ui->HighSlider->setRange(0,255);
    ui->LowSlider->setRange(0,255);
    ui->HoughSlider->setRange(0,100);
    Hvali = new QIntValidator(0,255,this);
    Lvali = new QIntValidator(0,255,this);
    Houghvali = new QIntValidator(0,100,this);
    ui->HighEdit->setValidator(Hvali);
    ui->LowEdit->setValidator(Lvali);
    ui->HoughEdit->setValidator(Houghvali);
    renovate();

    connect(ui->HighEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
    connect(ui->HighSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));

    connect(ui->LowEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
    connect(ui->LowSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));

    connect(ui->HoughEdit,SIGNAL(returnPressed()),this,SLOT(EditHander()));
    connect(ui->HoughSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));

    ui->HoughEdit->setEnabled(false);
    ui->HoughSlider->setEnabled(false);
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
        Houghalpha = 50;
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();

    }

}

void EdgeDetection::renovate()
{
    ui->HighEdit->setText(QString::number(Halpha));
    ui->HighSlider->setValue(Halpha);
    ui->LowEdit->setText(QString::number(Lalpha));
    ui->LowSlider->setValue(Lalpha);
    ui->HoughEdit->setText(QString::number(Houghalpha));
    ui->HoughSlider->setValue(Houghalpha);
    if(flag == 0)
    {
        Canny( mImage, OutImage, Lalpha, Halpha, 3);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
    else if(flag == 1)
    {
        Canny( mImage, mImage, Lalpha, Halpha, 3);
        cvtColor(mImage, OutImage, COLOR_GRAY2BGR);
        vector<Vec4i> lines;
        HoughLinesP(mImage,lines,1,CV_PI/180,Houghalpha,Houghalpha,10);
        for( size_t i = 0; i < lines.size(); i++ )
        {
          Vec4i l = lines[i];
          line( OutImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3);
        }

        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }
    else if(flag == 2)
    {
        cvtColor(mImage, OutImage, COLOR_GRAY2BGR);
        vector<Vec3f> circles;
        HoughCircles( mImage, circles, HOUGH_GRADIENT, 1, Houghalpha, Halpha, Lalpha);
        for( size_t i = 0; i < circles.size(); i++ )
        {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // circle center
            circle( OutImage, center, 3, Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle( OutImage, center, radius, Scalar(0,0,255), 3, 8, 0 );
        }
        qDebug()<<"OK";
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
    }


}

void EdgeDetection::EditHander()
{
    Halpha = ui->HighEdit->text().toInt();
    Lalpha = ui->LowEdit->text().toInt();
    Houghalpha = ui->HoughEdit->text().toInt();
    if(Halpha <= Lalpha)
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("高阈值不得小于低阈值"));
    }
    else
    {
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
    }

}

void EdgeDetection::SliderHander(int)
{
    Halpha = ui->HighSlider->value();
    Lalpha = ui->LowSlider->value();
    Houghalpha = ui->HoughSlider->value();
    if(Halpha <= Lalpha)
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("高阈值不得小于低阈值"));
    }
    else
    {
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
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


void EdgeDetection::on_HoughLineBox_stateChanged(int arg1)
{

    if(arg1 == 0&& flag == 1)
    {
        flag = 0;
        ui->HoughEdit->setEnabled(false);
        ui->HoughSlider->setEnabled(false);
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
    }
    else if(arg1 == 2)
    {
        flag = 1;
        ui->HoughEdit->setEnabled(true);
        ui->HoughSlider->setEnabled(true);
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
        ui->HoughCircleBox->setCheckState(Qt::Unchecked);

    }
}


void EdgeDetection::on_HoughCircleBox_stateChanged(int arg1)
{

    if(arg1 == 0&& flag == 2)
    {

        flag = 0;
        ui->HoughEdit->setEnabled(false);
        ui->HoughSlider->setEnabled(false);
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
    }
    else if(arg1 == 2)
    {
        flag = 2;
        ui->HoughEdit->setEnabled(true);
        ui->HoughSlider->setEnabled(true);
        cvtColor( MajorImage, GraImage, COLOR_BGR2GRAY );
        cv::blur(GraImage,mImage,Size(3,3));
        renovate();
        ui->HoughLineBox->setCheckState(Qt::Unchecked);

    }
}



