#include "qmavlinknpu.h"
#include "./ui_qmavlinknpu.h"

using namespace mavsdk;
using namespace std;

QMavlinkNpu::QMavlinkNpu(QWidget *parent): 
    QMainWindow(parent), 
    ui(new Ui::QMavlinkNpu)
{
    ui->setupUi(this);
    ConnectionResult connection_result = mavsdk.add_any_connection(connection_url);

    if(connection_result != ConnectionResult::Success)
    {
        std::cout << "Connection failed: " << connection_result << std::endl;
        // return;
    }
    else std::cout << "Connection success!" << std::endl;
    mavsdk.subscribe_on_new_system([](){
        cout << "Discovered new system\n";
    });

    for(auto system : mavsdk.systems())
    {
        cout << "Found system with MAVLink system ID: " << static_cast<int>(system->get_system_id())
             << ", connected: " << (system->is_connected() ? "yes" : "no")
             << ", has autopilot: " << (system->has_autopilot() ? "yes" : "no") << '\n';
    }

    auto system = mavsdk.systems()[0];
    telemetry = new Telemetry{system};
    
    main_timer = new QTimer(this);
    connect(main_timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    main_timer->start();

/*
euler_angle:
{
    roll_deg: 0.921273708343506
    pitch_deg: -0.0133227771148086
    yaw_deg: -28.6466178894043
    timestamp_us: 1030948000
}
*/
}

void QMavlinkNpu::updateTime()
{
    ui->label->setText(QString::fromStdString
    (
        "Roll: " + to_string(telemetry->attitude_euler().roll_deg)
        + "\nPitch: " + to_string(telemetry->attitude_euler().pitch_deg)
        + "\nYaw: " + to_string(telemetry->attitude_euler().yaw_deg)
    )
    );
}


QMavlinkNpu::~QMavlinkNpu()
{
    delete ui;
}

