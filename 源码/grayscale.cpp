#include "grayscale.h"
#include "ui_grayscale.h"

Grayscale::Grayscale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Grayscale)
{
    ui->setupUi(this);
    alpha = 100;
    flag = 1;
    //connect(ui->checkBox,SIGNAL(stateChanged(int)),this,SLOT(change(int)));

    vali = new QIntValidator(0,255,this);
    ui->lineEdit->setValidator(vali);
    ui->lineEdit->setText(QString::number(alpha));
    ui->lineEdit->setEnabled(false);

    ui->horizontalSlider->setRange(0,255);
    ui->horizontalSlider->setValue(alpha);
    ui->horizontalSlider->setEnabled(false);

    ui->OTSUButton->setEnabled(false);

    connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(SliderHander(int)));



}

Grayscale::~Grayscale()
{
    delete ui,vali;
}

void Grayscale::ReceiveCode(int code)
{
    if(code == GRAYSCALE)
    {
        OutImage.release();
        GraImage.release();
        //GraImage = MajorImage.
        if(MajorImage.type() != CV_8UC1)
        {
            cvtColor(MajorImage, GraImage, COLOR_BGR2GRAY);
        }
        else
        {
            GraImage = MajorImage.clone();
        }

        QPixmap pixmap = MatToPixmap(GraImage);
        ui->img->setPixmap(pixmap);
        OutImage = GraImage.clone();
        //qDebug() << OutImage.type();
        alpha = 100;
        ui->lineEdit->setText(QString::number(alpha));
        ui->lineEdit->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
        ui->horizontalSlider->setValue(alpha);
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->OTSUButton->setEnabled(false);



    }
}

void Grayscale::change(int state)
{
    //qDebug()<<state;

}

void Grayscale::EditHander()
{
    alpha = ui->lineEdit->text().toDouble();
    ui->horizontalSlider->setValue(alpha);
    threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void Grayscale::SliderHander(int value)
{

    alpha = value;
    ui->lineEdit->setText(QString::number(alpha));
    threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void Grayscale::on_SaveButton_clicked()
{
    if(!OutImage.empty())
    {
        QString dir = QFileDialog::getSaveFileName(
                            this,
                            tr("保存文件"),
                            "",
                            "Images (*.png *.xpm *.jpg *.tif)");
        //OutImage.type() = CV_8UC1;
        QImage img = MatToImage(OutImage);
        img.save(dir);
    }
}



void Grayscale::on_OTSUButton_clicked()
{
    alpha = Otus(GraImage);
    qDebug()<<alpha;
    ui->horizontalSlider->setValue(alpha);
    ui->lineEdit->setText(QString::number(alpha));
    threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);

}

int Grayscale::Otus(Mat img)
{
    int Pixnum[256]{0};
    int Nsum = img.rows * img.cols;
    double u = 0;
    for (int i = 0; i < img.rows; i += 1)
    {
        uchar* p = img.ptr<uchar>(i);
        for (int j = 0; j < img.cols; j++)
        {
            double n = p[j];
            Pixnum[(int)n]++;
        }
    }

    for (int i = 0; i < 256; i++)
    {
        u += Pixnum[i] * (i + 1);
    }
    u = u / Nsum;

    double sum0 = 0, sum1 = 0;
    double Nsum0 = 0, Nsum1 = 0;
    double w0 = 0, w1 = 0;
    double u0 = 0, u1 = 0;
    double g = 0,maxg = 0,cnt = 0;
    Nsum0 = Pixnum[0];
    Nsum1 = Nsum - Nsum0;
    sum0 += Nsum0 * 1;
    sum1 += u * Nsum - sum0;
    w0 = Nsum0 / Nsum;
    w1 = Nsum1 / Nsum;
    u0 = sum0 / Nsum0;
    u1 = sum1 / Nsum1;
    g = w0 * w1 * (u0 - u1) * (u0 - u1);
    //maxg = g;
    cnt = 1;
    for (int i = 1; i < 256; i++)
    {
        Nsum0 += Pixnum[i];
        sum0 += Pixnum[i] * (i + 1);
        w0 = Nsum0 / Nsum;
        u0 = sum0 / Nsum0;

        Nsum1 -= Pixnum[i];
        sum1 -= Pixnum[i] * (i + 1);
        w1 = Nsum1 / Nsum;
        u1 = sum1 / Nsum1;

        g = w0 * w1 * (u0 - u1) * (u0 - u1);
        //qDebug()<<i<<" "<<g;
        if(isnan(g) != 0 || isinf(g) != 0)continue;
        qDebug()<<i<<" "<<g;
        if (g > maxg)
        {
            maxg = g;
            cnt = i + 1;
        }
    }
    return cnt;
    //cout << cnt << endl;

//	for (int i = 0; i < img.rows; i += 1)
//	{
//		uchar* p = img.ptr<uchar>(i);
//		for (int j = 0; j < img.cols; j++)
//		{
//			p[j] = p[j] <= cnt ? 0 : 255;
//		}
//	}
//	return img;

}

void Grayscale::CameraHandle(int code)
{
    if(code == GRAYSCALE)
    {
        if(flag == 0)
        {
            cvtColor(MajorImage, GraImage, COLOR_BGR2GRAY);
            //threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
            QPixmap pixmap = MatToPixmap(GraImage);
            ui->img->setPixmap(pixmap);
        }
        else if(flag == 1)
        {
            cvtColor(MajorImage, GraImage, COLOR_BGR2GRAY);
            threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
            QPixmap pixmap = MatToPixmap(OutImage);
            ui->img->setPixmap(pixmap);
        }
    }
}





void Grayscale::on_checkBox_stateChanged(int arg1)
{
    //qDebug()<<"1:"<<arg1;
    if(arg1 == 0&& flag == 1)
    {
        QPixmap pixmap = MatToPixmap(GraImage);
        ui->img->setPixmap(pixmap);
        ui->horizontalSlider->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        ui->OTSUButton->setEnabled(false);
        OutImage = GraImage.clone();
        flag = 0;

    }
    else if(arg1 == 2)
    {
        ui->horizontalSlider->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->OTSUButton->setEnabled(true);
        alpha = ui->lineEdit->text().toInt();
        threshold(GraImage, OutImage, alpha, 255, THRESH_BINARY);
        QPixmap pixmap = MatToPixmap(OutImage);
        ui->img->setPixmap(pixmap);
        flag = 1;
    }
}




