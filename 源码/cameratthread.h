#ifndef CAMERATTHREAD_H
#define CAMERATTHREAD_H

#include "generalfunction.h"

class CameraTThread: public QThread
{
    Q_OBJECT

public:
    CameraTThread();
    VideoCapture cap;
private:
  void run() override;

signals:
    void CameraCode(int);

};

#endif // CAMERATTHREAD_H
