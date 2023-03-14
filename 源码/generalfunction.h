#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H


#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
using namespace cv;
#include <QImage>
#include<iostream>
#include<vector>
#include <QFileDialog>
#include<iostream>
#include<vector>
using namespace std;
#include "QDebug"
#include "QIntValidator"
#include <QMessageBox>
#include<math.h>
#include "FFT.h"
#include <QThread>

#include "generalinterface.h"
#include "resize.h"
#include "linearblending.h"
#include "brightnesscontrast.h"
#include "grayscale.h"
#include "gaussianfiltering.h"
#include "edgedetection.h"
#include "morphology.h"
#include "frequencydomain.h"
#include "equalization.h"
#include "cameratthread.h"

extern Mat MajorImage;
extern int Nowcode;
extern bool CameraFlag;
enum
{
    GENERALINTERFACE = 0,
    RESIZE,
    LINEARBLENDING,
    BRIGHTNESSCONTRAST,
    GRAYSCALE,
    GAUSSIANFILTERING,
    EDGEDETECTION,
    MORPHOLOGY,
    FREQUENCYDOMAIN,
    EQUALIZATION
};


QImage MatToImage(const Mat &src);
QPixmap MatToPixmap(const Mat &src);




#endif // GENERALFUNCTION_H
