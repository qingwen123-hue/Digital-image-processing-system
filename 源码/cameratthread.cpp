#include "cameratthread.h"

CameraTThread::CameraTThread()
{

}

void CameraTThread::run()
{
    while(1)
    {
        if(CameraFlag == 1)
        {
           cap.open(0);
           while(CameraFlag == 1)
           {
               cap.read(MajorImage);
               emit CameraCode(Nowcode);
               waitKey(30);
           }
           cap.release();
        }
        else
        {
            while(CameraFlag == 0);
        }
    }
}

