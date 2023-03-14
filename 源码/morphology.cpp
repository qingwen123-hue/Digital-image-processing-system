#include "morphology.h"
#include "ui_morphology.h"

Morphology::Morphology(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Morphology)
{
    ui->setupUi(this);
    Evali = new QIntValidator(1,100,this);
    ui->ElementEdit->setValidator(Evali);
    ui->ElementEdit->setText(QString::number(3));
    flag = 0;
    size = 3;
    connect(ui->ElementEdit,SIGNAL(editingFinished()),this,SLOT(EditHander()));
}

Morphology::~Morphology()
{
    delete ui,Evali;
}

void Morphology::ReceiveCode(int code)
{
    if(code == MORPHOLOGY)
    {
        OutImage.release();
        OutImage = MajorImage;
        QPixmap pixmap = MatToPixmap(MajorImage);
        ui->img->setPixmap(pixmap);
    }
}

void Morphology::on_ErodingButton_clicked()
{
    Handle(0);
    flag = 0;
}


void Morphology::on_DilatingButton_clicked()
{
    Handle(1);
    flag = 1;
}


void Morphology::on_SaveButton_clicked()
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

//enum MorphTypes{
//    MORPH_ERODE    = 0, //腐蚀
//    MORPH_DILATE   = 1, //膨胀
//    MORPH_OPEN     = 2, //开操作
//    MORPH_CLOSE    = 3, //闭操作
//    MORPH_GRADIENT = 4, //梯度操作
//    MORPH_TOPHAT   = 5, //顶帽操作
//    MORPH_BLACKHAT = 6, //黑帽操作
//    MORPH_HITMISS  = 7
//};


void Morphology::on_OpeningButton_clicked()
{
    Handle(2);
    flag = 2;
}


void Morphology::on_ClosingButton_clicked()
{
    Handle(3);
    flag = 3;
}


void Morphology::on_TopButton_clicked()
{
    Handle(5);
    flag = 5;
}


void Morphology::on_BlackButton_clicked()
{
    Handle(6);
    flag = 6;
}


void Morphology::on_GradientButton_clicked()
{
    Handle(4);
    flag = 4;
}

void Morphology::EditHander()
{
    int i = ui->ElementEdit->text().toInt();
    if(i % 2 != 1 )
    {
        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("核大小应为奇数"));
        return;
    }
    size = i;
}

void Morphology::Handle(int code)
{
    OutImage.release();
//    int size = ui->ElementEdit->text().toInt();
//    if(size % 2 != 1 )
//    {
//        QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("核大小应为奇数"));
//        return;
//    }
    Mat element = getStructuringElement(MORPH_RECT, Size(size, size));
    morphologyEx(MajorImage, OutImage, code,element);
    QPixmap pixmap = MatToPixmap(OutImage);
    ui->img->setPixmap(pixmap);
}

void Morphology::CameraHandle(int code)
{
    if(code == MORPHOLOGY)
    {
        Handle(flag);
    }
}

