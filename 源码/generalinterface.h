#ifndef GENERALINTERFACE_H
#define GENERALINTERFACE_H

#include "generalfunction.h"

using namespace std;
namespace Ui {
class GeneralInterface;
}

class GeneralInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneralInterface(QWidget *parent = nullptr);
    ~GeneralInterface();
    Mat OutImage;

private slots:
    void ReceiveCode(int code);
    void on_SaveButton_clicked();
    void CameraHandle(int code);

signals:
    void Camerasignals(int code);
private:
    Ui::GeneralInterface *ui;
};

#endif // GENERALINTERFACE_H
