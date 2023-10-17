#ifndef QMAVLINKNPU_H
#define QMAVLINKNPU_H

#include <QMainWindow>
#include <QString>

#include <iostream>
#include <string>

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/info/info.h>
#include <mavsdk/plugins/telemetry/telemetry.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QMavlinkNpu; }
QT_END_NAMESPACE

class QMavlinkNpu : public QMainWindow
{
    Q_OBJECT

public:
    mavsdk::Mavsdk mavsdk;
    std::string connection_url = "serial:///dev/ttyACM0:57600";
    
    QMavlinkNpu(QWidget *parent = nullptr);
    ~QMavlinkNpu();

private:
    Ui::QMavlinkNpu *ui;
};
#endif // QMAVLINKNPU_H
