#include "resize.h"
#include "ui_resize.h"

ReSize::ReSize(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReSize)
{
    ui->setupUi(this);
    Wvali = new QIntValidator(0,550,this);
    ui->widthEdit->setValidator(Wvali);
    Hvali = new QIntValidator(0,550,this);
    ui->heightEdit->setValidator(Hvali);
    // connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(ClickItem(int)));
    connect(ui->widthEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
    connect(ui->heightEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
}

ReSize::~ReSize()
{
    delete ui,Wvali,Hvali;
}

void ReSize::ReceiveCode(int code)
{
    if(code == RESIZE)
    {
        OutImage.release();
        //OutImage = MajorImage;
        QPixmap pixmap = MatToPixmap(MajorImage);
        ui->img->setPixmap(pixmap);
        width = MajorImage.cols;
        height = MajorImage.rows;
        ui->widthEdit->setText(QString::number(width));
        ui->heightEdit->setText(QString::number(height));
    }
}

void ReSize::SizeChange(int w, int h)
{
    cv::resize(MajorImage, OutImage, Size(w, h), INTER_LINEAR);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void ReSize::EditHander()
{
    width = ui->widthEdit->text().toInt();
    height = ui->heightEdit->text().toInt();
    SizeChange(width,height);
}

void ReSize::on_SaveButton_clicked()
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

void ReSize::CameraHandle(int code)
{
    if(code == RESIZE)
    {
        SizeChange(width,height);
    }
}

