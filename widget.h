#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QBitArray>
#include <QTimer>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QPainter>
#include <QPointF>
#include <QProgressBar>
#include <QPushButton>
#include <QColor>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    static const int command_tag =          0xAA;
    static const int opcode_readstatus =    0x00;
    static const int opcode_writesetting =  0x01;
    static const int opcode_liftup =        0x02;
    static const int opcode_ledsw =         0x03;
    static const int opcode_pdget =         0x04;
    static const int opcode_verget =        0x05;
    static const int opcode_ret_base =      0xA0;
    static const int opcode_tester =        0xF0;

    static const int timer_T =              1;
    static const int pre_heating_time =     5;    //sec

    static const int timer_log =            60*60*2;
    static const int logfilemax =           1000;

    static const int PDsamplerate =         5;  //sec

    static const int SerialResetTime =      3;  //sec
    ~Widget();

private slots:
    void initial();

    void ui_initial();

    void serialport_initial();

    void timer_initial();

    void draw_initial();

    void timeout_todo();

    void read_real_temp();

    void remaining_time(int cycleT);

    void savelog();

    void PD_draw(int cycleT);

    void Temp_draw(int cycleT);

    void Open_Device();

    void read_Com();

    void Command_run(int *com);

    QBitArray char_to_QBitArray(char input);

    void Command_ReadStatus();

    void Command_WriteSetting(int Temp_int, int Temp_deg);

    void Command_LiftUp(int liftup_1, int liftup_2);

    void Command_LEDSW(bool ONOFF);

    void Command_PDGet();

    void Command_VerGet();

    void Command_Tester();

    QString FileName_Setting(QString FileName);

    QString logfile_setting(QString Path, QString FileName);

    void logfile_max();

    void logfile_write(QString file, QByteArray T1_log, QByteArray T2_log, QByteArray T3_log,
                       QByteArray T4_log, QByteArray T5_log, QByteArray T6_log,
                       QByteArray Fan1_log, QByteArray Fan2_log, QByteArray Fan3_log, QByteArray Fan4_log,
                       QByteArray wellstatus1_log, QByteArray wellstatus2_log ,QByteArray tester);

    void logfile_write_title(QString file);

    void PDfile_write(QString file, QByteArray time,
                              QByteArray ch1, QByteArray ch2, QByteArray ch3, QByteArray ch4,
                              QByteArray ch5, QByteArray ch6, QByteArray ch7, QByteArray ch8,
                              QByteArray ch9, QByteArray ch10, QByteArray ch11, QByteArray ch12);

    void PDfile_write_title(QString file);

    void Tempfile_write(QString file, QByteArray time,
                              QByteArray TP1, QByteArray TP2, QByteArray TP3, QByteArray TP4,
                              QByteArray TP5, QByteArray TP6);

    void Tempfile_write_title(QString file);

    bool eventFilter(QObject *obj, QEvent *event);

    void PDdrawnewpoint(int x, int y1, int y2, int y3, int y4, int y5, int y6,
                        int y7, int y8, int y9, int y10, int y11, int y12);

    void Tempdrawnewpoint(int x, int y1, int y2, int y3, int y4, int y5, int y6);

    void LED_heating_en();

    void progressbar_update(QProgressBar *PB, int well_time, double TP);

    void LED_yellow(QPushButton *PB);

    void LED_red(QPushButton *PB);

    void LED_green(QPushButton *PB);

    void LED_blue(QPushButton *PB);

    void LED_orange(QPushButton *PB);

    void num_input(bool sw, int num);

    void num_temp(int num);

//-------------------------------------------------------------------------------------

    void on_pushButton_clicked();

    void on_pushButton_Tube_1_clicked();

    void on_pushButton_Tube_2_clicked();

    void on_pushButton_Tube_3_clicked();

    void on_pushButton_Tube_4_clicked();

    void on_pushButton_Tube_5_clicked();

    void on_pushButton_Tube_6_clicked();

    void on_pushButton_Tube_7_clicked();

    void on_pushButton_Tube_8_clicked();

    void on_pushButton_Tube_9_clicked();

    void on_pushButton_Tube_10_clicked();

    void on_pushButton_Tube_11_clicked();

    void on_pushButton_Tube_12_clicked();

    void on_pushButton_Logo_clicked();

    void on_pushButton_Draw_clicked();

    void on_radioButton_setTargetTemp_clicked();

    void on_radioButton_setHeatingTime_clicked();

    void on_pushButton_num_C_clicked();

    void on_pushButton_num_0_clicked();

    void on_pushButton_num_1_clicked();

    void on_pushButton_num_2_clicked();

    void on_pushButton_num_3_clicked();

    void on_pushButton_num_4_clicked();

    void on_pushButton_num_5_clicked();

    void on_pushButton_num_6_clicked();

    void on_pushButton_num_7_clicked();

    void on_pushButton_num_8_clicked();

    void on_pushButton_num_9_clicked();

    void on_pushButton_num_OK_clicked();

    void on_checkBox_PD_1_clicked();

    void on_checkBox_PD_2_clicked();

    void on_checkBox_PD_3_clicked();

    void on_checkBox_PD_4_clicked();

    void on_checkBox_PD_5_clicked();

    void on_checkBox_PD_6_clicked();

    void on_checkBox_PD_7_clicked();

    void on_checkBox_PD_8_clicked();

    void on_checkBox_PD_9_clicked();

    void on_checkBox_PD_10_clicked();

    void on_checkBox_PD_11_clicked();

    void on_checkBox_PD_12_clicked();

    void on_pushButton_Draw_temp_clicked();

private:
    Ui::Widget *ui;
    QSerialPort serial;
    int serial_disconnect_timer;

    QPushButton *PB_LED_1, *PB_LED_2, *PB_LED_3, *PB_LED_4, *PB_LED_5, *PB_LED_6,
                *PB_LED_7, *PB_LED_8, *PB_LED_9, *PB_LED_10, *PB_LED_11, *PB_LED_12;

    QString Version;
    QString RedLED;
    QString YellowLED;
    QString GreenLED;
    QString BlueLED;
    QString OrangeLED;
    QString PurpleLED;

    QString logdirname, logPath;
    QDir logdir;
    QString csvFile, PDfile, Tempfile, locationdir;

    int RXD_counter, RXD_length, RXD_cks, comm_num;
    int command[30];

    int well_timer[12];
    int Heating_Time, PD_time;
    int log_sec_time, filepart;
    QString oldfilename;

    bool heating_en, PD_draw_en;
    int pre_heating_timer;

    QPointF points_1[600], points_2[600], points_3[600], points_4[600], points_5[600], points_6[600],
            points_7[600], points_8[600], points_9[600], points_10[600], points_11[600], points_12[600];
    int pointnum;
    int PDdisplayPointsec;

    double setting_temp;
    double real_temp1, real_temp2, real_temp3, real_temp4, real_temp5, real_temp6;
    int Fan1, Fan2, Fan3, Fan4;
    char trigger_point_1, trigger_point_2;

    int PD_timer;
    double PDch1, PDch2, PDch3, PDch4, PDch5, PDch6, PDch7, PDch8, PDch9, PDch10, PDch11, PDch12;

    double tester;
    bool pre_heating_timer_en;

    bool num_sw;
    int targettemp_max, heatingtime_max;

    bool Temp_draw_en;
    QPointF TempPF1[300], TempPF2[300], TempPF3[300], TempPF4[300], TempPF5[300], TempPF6[300];
    int Temppointnum;
};

#endif // WIDGET_H
