#include "widget.h"
#include "ui_widget.h"

void Widget::initial()
{
    Version = "01.02.03";

    RXD_counter = 0;

    Heating_Time = (ui->lcdNumber_Heatingtime->value())*60;  //sec
    setting_temp = (ui->lcdNumber_Targettemp->value());
    PD_time = Heating_Time;
    PDdisplayPointsec = 600/(PD_time/PDsamplerate);

    for(int i=0;i<12;i++)
    {
        well_timer[i] = (-1);

    }

    heating_en = false;
    pre_heating_timer = 0;
    pre_heating_timer_en = false;

    RedLED = ":/Icon/Red_LED.png";
    YellowLED = ":/Icon/Yellow_LED.png";
    GreenLED = ":/Icon/Green_LED.png";
    BlueLED = ":/Icon/Blue_LED.png";
    OrangeLED = ":/Icon/Orange_LED.png";
    PurpleLED = ":/Icon/Purple_LED.png";

    locationdir = QDir::currentPath();
    logPath = QDir::rootPath();
    logPath += "media/pi/";
    logdirname = "log";
    log_sec_time = 0;
    filepart = 2;

    pointnum = 0;
    PD_draw_en = false;
    PD_timer = 0;

    Temp_draw_en = false;
    Temppointnum = 0;

    num_sw = false;
    targettemp_max = 110;
    heatingtime_max = 30;

    serial_disconnect_timer = 0;

    ui_initial();
    serialport_initial();
    timer_initial();
    draw_initial();  
}

void Widget::ui_initial()
{
    ui->label_Version->setText(Version);
    ui->lcdNumber_Targettemp->setPalette(Qt::darkRed);
    //ui->lcdNumber_Heatingtime->setPalette(Qt::darkRed);
    ui->tabWidget->setCurrentIndex(0);

    PB_LED_1 = ui->pushButton_Tube_1;
    PB_LED_2 = ui->pushButton_Tube_2;
    PB_LED_3 = ui->pushButton_Tube_3;
    PB_LED_4 = ui->pushButton_Tube_4;
    PB_LED_5 = ui->pushButton_Tube_5;
    PB_LED_6 = ui->pushButton_Tube_6;
    PB_LED_7 = ui->pushButton_Tube_7;
    PB_LED_8 = ui->pushButton_Tube_8;
    PB_LED_9 = ui->pushButton_Tube_9;
    PB_LED_10 = ui->pushButton_Tube_10;
    PB_LED_11 = ui->pushButton_Tube_11;
    PB_LED_12 = ui->pushButton_Tube_12;

    ui->tabWidget->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
    //ui->tabWidget->setAttribute(Qt::WA_TranslucentBackground,true);
    //ui->Tubes->setAttribute(Qt::WA_TranslucentBackground,true);
    //ui->PhotoDiode->setAttribute(Qt::WA_TranslucentBackground,true);
    //ui->Setting->setAttribute(Qt::WA_TranslucentBackground,true);
}

void Widget::serialport_initial()
{
    bool COM = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if(info.portName() != "ttyAMA0")
        {
            serial.setPortName(info.portName());
        }
        if(info.portName() == "COM5")
        {
            COM = true;
        }
    }
    if(COM)
        serial.setPortName("COM5");
    serial.setBaudRate(serial.Baud9600);
    serial.setDataBits(serial.Data8);
    serial.setFlowControl(serial.NoFlowControl);
    serial.setParity(serial.NoParity);
    serial.setStopBits(serial.OneStop);
    serial.close();
    if(serial.open(QIODevice::ReadWrite))
    {
        connect(&serial,SIGNAL(readyRead()),this,SLOT(read_Com()));
        serial_disconnect_timer = SerialResetTime;
    }
    else
    {
        serial.close();
    }
}

void Widget::timer_initial()
{
    QTimer *read_temp_timer = new QTimer(this);
    connect(read_temp_timer, SIGNAL(timeout()), this, SLOT(timeout_todo()));
    read_temp_timer->start(timer_T*1000);
}

void Widget::draw_initial()
{
    ui->widget_DrawIn->installEventFilter(this);
    ui->widget_TempDisplay->installEventFilter(this);
}
