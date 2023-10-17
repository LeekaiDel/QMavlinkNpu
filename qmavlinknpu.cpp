#include "qmavlinknpu.h"
#include "./ui_qmavlinknpu.h"

using namespace mavsdk;

QMavlinkNpu::QMavlinkNpu(QWidget *parent): 
    QMainWindow(parent), 
    ui(new Ui::QMavlinkNpu)
{
    ConnectionResult connection_result = mavsdk.add_any_connection(connection_url);
    
    if(connection_result != ConnectionResult::Success)
    {
        std::cout << "Connection failed: " << connection_result << std::endl;
        return;
    }
    else std::cout << "Connection success!" << std::endl;

    ui->setupUi(this);
}

QMavlinkNpu::~QMavlinkNpu()
{
    delete ui;
}

