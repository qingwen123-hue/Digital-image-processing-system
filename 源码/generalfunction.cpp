#include "generalfunction.h"
Mat MajorImage;
int Nowcode;
bool CameraFlag;

QImage MatToImage(const Mat &src)
{
    //CV_8UC1 8位无符号的单通道---灰度图片
    if(src.type() == CV_8UC1)
    {
        vector<uchar> imgBuf;
        imencode(".bmp", src, imgBuf);

        QByteArray baImg((char*)imgBuf.data(), static_cast<int>(imgBuf.size()));
        QImage image;
        image.loadFromData(baImg, "BMP");
        return image;
    }
    //为3通道的彩色图片
    else if(src.type() == CV_8UC3)
    {
        //得到图像的的首地址
        const uchar *pSrc = (const uchar*)src.data;
        //以src构造图片
        QImage qImage(pSrc,src.cols,src.rows,src.step,QImage::Format_RGB888);
        //在不改变实际图像数据的条件下，交换红蓝通道
        return qImage.rgbSwapped();
    }
    //四通道图片，带Alpha通道的RGB彩色图像
    else if(src.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)src.data;
        QImage qImage(pSrc, src.cols, src.rows, src.step, QImage::Format_ARGB32);
        //返回图像的子区域作为一个新图像
        return qImage.copy();
    }
    else
    {
        return QImage();
    }
}

QPixmap MatToPixmap(const Mat &src)
{
    QImage aa = MatToImage(src);
    return QPixmap::fromImage(aa);
}

