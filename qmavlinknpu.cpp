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
    }
    else std::cout << "Connection success!" << std::endl;
    
    while(mavsdk.systems().size() == 0){} // Ждем когда появится хотя бы одна система 
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
}

void QMavlinkNpu::updateTime()
{
    ui->label->setText(QString::fromStdString
    (
        "Roll angle: " + to_string(telemetry->attitude_euler().roll_deg) + "\n" + 
        "Pitch angle: " + to_string(telemetry->attitude_euler().pitch_deg) + "\n" + 
        "Yaw angle: " + to_string(telemetry->attitude_euler().yaw_deg)
    )
    );
}


QMavlinkNpu::~QMavlinkNpu()
{
    delete ui;
}

