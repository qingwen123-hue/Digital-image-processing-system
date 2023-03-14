#include"FFT.h"
#include <iostream>
#include<opencv2/opencv.hpp>
/*///////////////////////////////
ImgFft(Mat InputImg_T, Mat* OutputImg_F, Mat *TransformImg)
函数功能：输入时域图像，返回傅里叶变化复数结果和可显示的频谱图
InputImg_T：输入图像
OutputImg_F：可显示的频谱图
TransformImg：傅里叶变化结果
///////////////////////////////*/
void FftOperation::ImgFft(Mat InputImg_T, Mat* OutputImg_F, Mat *TransformImg)
{
    if (InputImg_T.empty())
    {
        cout << "InputImg_T is empty" << endl;
        return;
    }

    if (InputImg_T.type() == CV_8U)
    {
        //https://blog.csdn.net/LY_970909/article/details/125528940
        InputImg_T.convertTo(InputImg_T, CV_32FC1, 1 / 255.0);
    }


    int m = getOptimalDFTSize(InputImg_T.rows);
    int n = getOptimalDFTSize(InputImg_T.cols);
    copyMakeBorder(InputImg_T, InputImg_T, 0, m - InputImg_T.rows, 0, n - InputImg_T.cols, cv::BORDER_REPLICATE);

    Mat plane[] = { InputImg_T.clone(), Mat::zeros(InputImg_T.size() , CV_32FC1) };
    Mat complexIm;
    merge(plane, 2, complexIm);
    dft(complexIm, complexIm);

    *TransformImg = complexIm.clone();

    split(complexIm, plane);

    magnitude(plane[0], plane[1], *OutputImg_F); //计算复数的幅值，保存在output_image（频谱图）

    //6.前面得到的频谱图数级过大，不好显示，因此转换
    *OutputImg_F += Scalar(1);   // 取对数前将所有的像素都加1，防止log0
    log(*OutputImg_F, *OutputImg_F);   // 取对数
    normalize(*OutputImg_F, *OutputImg_F, 0, 1, NORM_MINMAX); //归一化

    ImgQuadrantCentralization(OutputImg_F);
    ImgQuadrantCentralization(&plane[0]);
    ImgQuadrantCentralization(&plane[1]);
    merge(plane, 2, *TransformImg);
}


/*/////////////////////////////////////
FftOperation::ImgIfft(Mat TransformImg, Mat* OutputImg_T)
函数功能：输入傅里叶变化结果，进行反傅里叶变化，输出结果图像
TransformImg：傅里叶变化结果
OutputImg_T：输出图像
////////////////////////////////////*/
void FftOperation::ImgIfft(Mat TransformImg, Mat* OutputImg_T)
{
    if (TransformImg.empty())
    {
        cout << "TransformImg is empty" << endl;
        return;
    }
    Mat iDft[] = { Mat_<float>(TransformImg), Mat::zeros(TransformImg.size(),CV_32F) };
    idft(TransformImg, TransformImg);//傅立叶逆变换
    split(TransformImg, iDft);//分离通道，主要获取0通道
    magnitude(iDft[0], iDft[1], iDft[0]); //计算复数的幅值，保存在iDft[0]
    normalize(iDft[0], iDft[0], 0, 1, NORM_MINMAX);//归一化处理
    *OutputImg_T = iDft[0].clone();
}

/*////////////////////////////////////
FftOperation::GaussianFilteringLow(Mat InTransformImg, Mat* OutTransformImg,int d0)
函数功能：进行低通滤波
InTransformImg：输入
OutTransformImg：输出结果
d0：滤波半径
////////////////////////////////////*/
void FftOperation::GaussianFilteringLow(Mat InTransformImg, Mat* OutTransformImg,int d0)
{
    if (InTransformImg.empty())
    {
        cout << "InTransformImg is empty" << endl;
        return;
    }
    if (d0 <= 0)
    {
        cout << "do <= 0,不和法" << endl;
        return;
    }
    if (d0 > InTransformImg.rows || d0 >= InTransformImg.cols)
    {
        cout << "do 大于输入图像半径" << endl;
        return;
    }
    Mat planes[] = { Mat_<float>(InTransformImg), Mat::zeros(InTransformImg.size(),CV_32F) };
    split(InTransformImg, planes);//分离通道，获取实部虚部
    int core_x = InTransformImg.rows / 2;//频谱图中心坐标
    int core_y = InTransformImg.cols / 2;
    float h;
    for (int i = 0; i < InTransformImg.rows; i++)
    {
        for (int j = 0; j < InTransformImg.cols; j++)
        {
            h = exp(-((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) / (d0 * d0));
            planes[0].at<float>(i, j) = planes[0].at<float>(i, j) * h;
            planes[1].at<float>(i, j) = planes[1].at<float>(i, j) * h;

        }
    }
    merge(planes, 2, *OutTransformImg);
}


/*////////////////////////////////////
FftOperation::GaussianFilteringHigh(Mat InTransformImg, Mat* OutTransformImg,int d0)
函数功能：进行高通滤波
InTransformImg：输入
OutTransformImg：输出结果
d0：滤波半径
////////////////////////////////////*/
void FftOperation::GaussianFilteringHigh(Mat InTransformImg, Mat* OutTransformImg, int d0)
{
    if (InTransformImg.empty())
    {
        cout << "InTransformImg is empty" << endl;
        return;
    }
    if (d0 <= 0)
    {
        cout << "do <= 0,不和法" << endl;
        return;
    }
    if (d0 > InTransformImg.rows || d0 >= InTransformImg.cols)
    {
        cout << "do 大于输入图像半径" << endl;
        return;
    }
    Mat planes[] = { Mat_<float>(InTransformImg), Mat::zeros(InTransformImg.size(),CV_32F) };
    split(InTransformImg, planes);//分离通道，获取实部虚部
    int core_x = InTransformImg.rows / 2;//频谱图中心坐标
    int core_y = InTransformImg.cols / 2;
    float h;
    for (int i = 0; i < InTransformImg.rows; i++)
    {
        for (int j = 0; j < InTransformImg.cols; j++)
        {
            h = exp(-((i - core_x) * (i - core_x) + (j - core_y) * (j - core_y)) / (d0 * d0));
            planes[0].at<float>(i, j) = planes[0].at<float>(i, j) * (1-h);
            planes[1].at<float>(i, j) = planes[1].at<float>(i, j) * (1-h);

        }
    }
    merge(planes, 2, *OutTransformImg);
}
/*//////////////////////////////////
FftOperation::ImgQuadrantCentralization(Mat* InputImg)
函数功能：对图像进行坐标变化，象限中心化
InputImg：输入图像
//////////////////////////////////*/
void FftOperation::ImgQuadrantCentralization(Mat* InputImg)
{

    if (InputImg->empty())
    {
        cout << "InputImg is empty" << endl;
        return;
    }
    //剪切和重分布幅度图像限
    *InputImg = (*InputImg)(Rect(0, 0, InputImg->cols & -2, InputImg->rows & -2));

    // 重新排列傅里叶图像中的象限，使原点位于图像中心
    int cx = InputImg->cols / 2;
    int cy = InputImg->rows / 2;
    Mat q0(*InputImg, Rect(0, 0, cx, cy));   // 左上区域
    Mat q1(*InputImg, Rect(cx, 0, cx, cy));  // 右上区域
    Mat q2(*InputImg, Rect(0, cy, cx, cy));  // 左下区域
    Mat q3(*InputImg, Rect(cx, cy, cx, cy)); // 右下区域

    //交换象限中心化
    Mat tmp;
    q0.copyTo(tmp); q3.copyTo(q0); tmp.copyTo(q3);//左上与右下进行交换
    q1.copyTo(tmp); q2.copyTo(q1); tmp.copyTo(q2);//右上与左下进行交换

}
