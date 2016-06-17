#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initial();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    setting_temp = ui->lcdNumber_Targettemp->value();
    int temp_int = ui->lcdNumber_Targettemp->intValue();
    int temp_deg = int((setting_temp - temp_int)*10);
    Command_WriteSetting(temp_int, temp_deg);
    pre_heating_timer = pre_heating_time;  //sec

    csvFile = logfile_setting(logdirname, "System.csv");
    logfile_write_title(csvFile);
}

void Widget::on_pushButton_Tube_1_clicked()
{
    if(well_timer[0] == (-2))
    {
        LED_green(PB_LED_1);
        ui->progressBar_tube_1->setValue(0);
        well_timer[0] = (-1);
    }
    else if(well_timer[0] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_1);
        well_timer[0] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_2_clicked()
{
    if(well_timer[1] == (-2))
    {
        LED_green(PB_LED_2);
        ui->progressBar_tube_2->setValue(0);
        well_timer[1] = (-1);
    }
    else if(well_timer[1] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_2);
        well_timer[1] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_3_clicked()
{
    if(well_timer[2] == (-2))
    {
        LED_green(PB_LED_3);
        ui->progressBar_tube_3->setValue(0);
        well_timer[2] = (-1);
    }
    else if(well_timer[2] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_3);
        well_timer[2] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_4_clicked()
{
    if(well_timer[3] == (-2))
    {
        LED_green(PB_LED_4);
        ui->progressBar_tube_4->setValue(0);
        well_timer[3] = (-1);
    }
    else if(well_timer[3] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_4);
        well_timer[3] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_5_clicked()
{
    if(well_timer[4] == (-2))
    {
        LED_green(PB_LED_5);
        ui->progressBar_tube_5->setValue(0);
        well_timer[4] = (-1);
    }
    else if(well_timer[4] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_5);
        well_timer[4] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_6_clicked()
{
    if(well_timer[5] == (-2))
    {
        LED_green(PB_LED_6);
        ui->progressBar_tube_6->setValue(0);
        well_timer[5] = (-1);
    }
    else if(well_timer[5] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_6);
        well_timer[5] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_7_clicked()
{
    if(well_timer[6] == (-2))
    {
        LED_green(PB_LED_7);
        ui->progressBar_tube_7->setValue(0);
        well_timer[6] = (-1);
    }
    else if(well_timer[6] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_7);
        well_timer[6] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_8_clicked()
{
    if(well_timer[7] == (-2))
    {
        LED_green(PB_LED_8);
        ui->progressBar_tube_8->setValue(0);
        well_timer[7] = (-1);
    }
    else if(well_timer[7] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_8);
        well_timer[7] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_9_clicked()
{
    if(well_timer[8] == (-2))
    {
        LED_green(PB_LED_9);
        ui->progressBar_tube_9->setValue(0);
        well_timer[8] = (-1);
    }
    else if(well_timer[8] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_9);
        well_timer[8] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_10_clicked()
{
    if(well_timer[9] == (-2))
    {
        LED_green(PB_LED_10);
        ui->progressBar_tube_10->setValue(0);
        well_timer[9] = (-1);
    }
    else if(well_timer[9] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_10);
        well_timer[9] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_11_clicked()
{
    if(well_timer[10] == (-2))
    {
        LED_green(PB_LED_11);
        ui->progressBar_tube_11->setValue(0);
        well_timer[10] = (-1);
    }
    else if(well_timer[10] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_11);
        well_timer[10] = Heating_Time;
    }
}

void Widget::on_pushButton_Tube_12_clicked()
{
    if(well_timer[11] == (-2))
    {
        LED_green(PB_LED_12);
        ui->progressBar_tube_12->setValue(0);
        well_timer[11] = (-1);
    }
    else if(well_timer[11] == (-1) && pre_heating_timer_en == true)
    {
        LED_red(PB_LED_12);
        well_timer[11] = Heating_Time;
    }
}

void Widget::on_pushButton_Logo_clicked()
{
    close();
}

void Widget::on_pushButton_Draw_clicked()
{
    PD_draw_en = true;
    pointnum = 0;
    PD_time = (ui->lcdNumber_Heatingtime->intValue())*60;
    PDdisplayPointsec = 600/(PD_time/PDsamplerate);

    PDfile = logfile_setting(logdirname, "PD.csv");
    PDfile_write_title(PDfile);
}

void Widget::on_radioButton_setTargetTemp_clicked()
{
    num_sw = false;
    ui->radioButton_setHeatingTime->setChecked(false);
}

void Widget::on_radioButton_setHeatingTime_clicked()
{
    num_sw = true;
    ui->radioButton_setTargetTemp->setChecked(false);
}

void Widget::on_pushButton_num_C_clicked()
{
    ui->lcdNumber_num->display(0);
}

void Widget::on_pushButton_num_0_clicked()
{
    num_temp(0);
}

void Widget::on_pushButton_num_1_clicked()
{
    num_temp(1);
}

void Widget::on_pushButton_num_2_clicked()
{
    num_temp(2);
}

void Widget::on_pushButton_num_3_clicked()
{
    num_temp(3);
}

void Widget::on_pushButton_num_4_clicked()
{
    num_temp(4);
}

void Widget::on_pushButton_num_5_clicked()
{
    num_temp(5);
}

void Widget::on_pushButton_num_6_clicked()
{
    num_temp(6);
}

void Widget::on_pushButton_num_7_clicked()
{
    num_temp(7);
}

void Widget::on_pushButton_num_8_clicked()
{
    num_temp(8);
}

void Widget::on_pushButton_num_9_clicked()
{
    num_temp(9);
}

void Widget::on_pushButton_num_OK_clicked()
{
    int inputval = ui->lcdNumber_num->intValue();
    num_input(num_sw, inputval);
    ui->lcdNumber_num->display(0);
    pre_heating_timer_en = false;

    setting_temp = ui->lcdNumber_Targettemp->value();
    int temp_int = ui->lcdNumber_Targettemp->intValue();
    int temp_deg = int((setting_temp - temp_int)*10);
    Command_WriteSetting(temp_int, temp_deg);
    pre_heating_timer = pre_heating_time;  //sec

    csvFile = logfile_setting(logdirname, "System.csv");
    logfile_write_title(csvFile);

    pointnum = 0;
    PD_time = (ui->lcdNumber_Heatingtime->intValue())*60;
    PDdisplayPointsec = 600/(PD_time/PDsamplerate);
}

void Widget::on_checkBox_PD_1_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_2_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_3_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_4_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_5_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_6_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_7_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_8_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_9_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_10_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_11_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_checkBox_PD_12_clicked()
{
    ui->widget_DrawIn->update();
}

void Widget::on_pushButton_Draw_temp_clicked()
{
    Temp_draw_en = true;
    Temppointnum = 0;

    Tempfile = logfile_setting(logdirname, "Temp.csv");
    Tempfile_write_title(Tempfile);
}
