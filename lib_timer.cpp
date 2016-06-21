#include "widget.h"
#include "ui_widget.h"

void Widget::timeout_todo()
{
    remaining_time(timer_T);
    read_real_temp();  
    savelog();
    PD_draw(timer_T);
    Temp_draw(timer_T);
    Command_Tester();
    //Command_VerGet();
    Open_Device();
}

void Widget::remaining_time(int cycleT)
{
    if(serial_disconnect_timer)
        serial_disconnect_timer--;
    if(pre_heating_timer > 0)
    {
        if((real_temp1-setting_temp)<=1 && (real_temp1-setting_temp)>=(-1))
        {
            pre_heating_timer_en = true;
            ui->lcdNumber_Targettemp->setPalette(Qt::lightGray);
        }
        if(pre_heating_timer_en)
            pre_heating_timer -= cycleT;
        if(pre_heating_timer <= 0)
        {
            pre_heating_timer = 0;

            if(!heating_en)
            {
                LED_heating_en();
            }
            heating_en = true;
            //ui->pushButton->setVisible(true);
        }
    }

    for(int i=0;i<12;i++)
    {
        if(well_timer[i] > 0)
        {
            well_timer[i] -= cycleT;
            if(well_timer[i] <= 0)
                well_timer[i] = 0;
        }
    }

    double TP = double(Heating_Time)/100;

    int well_lu_1 = 0xFF;
    int well_lu_2 = 0xFF;

    progressbar_update(ui->progressBar_tube_1, well_timer[0], TP);
    if(well_timer[0] == 0)
    {
        LED_red(PB_LED_1);
        well_lu_1 &= 0xFE;  // 11111110b
        well_timer[0] = (-2);
    }

    progressbar_update(ui->progressBar_tube_2, well_timer[1], TP);
    if(well_timer[1] == 0)
    {
        LED_red(PB_LED_2);
        well_lu_1 &= 0xFD;  // 11111101b
        well_timer[1] = (-2);
    }

    progressbar_update(ui->progressBar_tube_3, well_timer[2], TP);
    if(well_timer[2] == 0)
    {
        LED_red(PB_LED_3);
        well_lu_1 &= 0xFB;  // 11111011b
        well_timer[2] = (-2);
    }

    progressbar_update(ui->progressBar_tube_4, well_timer[3], TP);
    if(well_timer[3] == 0)
    {
        LED_red(PB_LED_4);
        well_lu_1 &= 0xF7;  // 11110111b
        well_timer[3] = (-2);
    }

    progressbar_update(ui->progressBar_tube_5, well_timer[4], TP);
    if(well_timer[4] == 0)
    {
        LED_red(PB_LED_5);
        well_lu_1 &= 0xEF;  // 11101111b
        well_timer[4] = (-2);
    }

    progressbar_update(ui->progressBar_tube_6, well_timer[5], TP);
    if(well_timer[5] == 0)
    {
        LED_red(PB_LED_6);
        well_lu_1 &= 0xDF;  // 11011111b
        well_timer[5] = (-2);
    }

    progressbar_update(ui->progressBar_tube_7, well_timer[6], TP);
    if(well_timer[6] == 0)
    {
        LED_red(PB_LED_7);
        well_lu_2 &= 0xFE;  // 11111110b
        well_timer[6] = (-2);
    }

    progressbar_update(ui->progressBar_tube_8, well_timer[7], TP);
    if(well_timer[7] == 0)
    {
        LED_red(PB_LED_8);
        well_lu_2 &= 0xFD;  // 11111101b
        well_timer[7] = (-2);
    }

    progressbar_update(ui->progressBar_tube_9, well_timer[8], TP);
    if(well_timer[8] == 0)
    {
        LED_red(PB_LED_9);
        well_lu_2 &= 0xFB;  // 11111011b
        well_timer[8] = (-2);
    }

    progressbar_update(ui->progressBar_tube_10, well_timer[9], TP);
    if(well_timer[9] == 0)
    {
        LED_red(PB_LED_10);
        well_lu_2 &= 0xF7;  // 11110111b
        well_timer[9] = (-2);
    }

    progressbar_update(ui->progressBar_tube_11, well_timer[10], TP);
    if(well_timer[10] == 0)
    {
        LED_red(PB_LED_11);
        well_lu_2 &= 0xEF;  // 11101111b
        well_timer[10] = (-2);
    }

    progressbar_update(ui->progressBar_tube_12, well_timer[11], TP);
    if(well_timer[11] == 0)
    {
        LED_red(PB_LED_12);
        well_lu_2 &= 0xDF;  // 11011111b
        well_timer[11] = (-2);
    }

    if((well_lu_1 != 0xFF) || (well_lu_2 != 0xFF))
        Command_LiftUp(well_lu_1, well_lu_2);
}

void Widget::read_real_temp()
{
    Command_ReadStatus();
}

void Widget::savelog()
{
    QByteArray T1_log, T2_log, T3_log, T4_log, T5_log, T6_log,
            Fan1_log, Fan2_log, Fan3_log, Fan4_log, wellstatus1_log, wellstatus2_log, tester_log;
    QByteArray time_log, ch1_log, ch2_log, ch3_log, ch4_log, ch5_log, ch6_log,
            ch7_log, ch8_log, ch9_log, ch10_log, ch11_log, ch12_log;
    QByteArray TempTime_log;

    T1_log.setNum(real_temp1);
    T2_log.setNum(real_temp2);
    T3_log.setNum(real_temp3);
    T4_log.setNum(real_temp4);
    T5_log.setNum(real_temp5);
    T6_log.setNum(real_temp6);
    Fan1_log.setNum(Fan1);
    Fan2_log.setNum(Fan2);
    Fan3_log.setNum(Fan3);
    Fan4_log.setNum(Fan4);
    wellstatus1_log.setNum(trigger_point_1, 2);
    wellstatus2_log.setNum(trigger_point_2, 2);
    tester_log.setNum(tester);

    time_log.setNum(pointnum*PDsamplerate);
    ch1_log.setNum(PDch1);
    ch2_log.setNum(PDch2);
    ch3_log.setNum(PDch3);
    ch4_log.setNum(PDch4);
    ch5_log.setNum(PDch5);
    ch6_log.setNum(PDch6);
    ch7_log.setNum(PDch7);
    ch8_log.setNum(PDch8);
    ch9_log.setNum(0);
    ch10_log.setNum(0);
    ch11_log.setNum(0);
    ch12_log.setNum(0);

    TempTime_log.setNum(Temppointnum);

    if(!csvFile.isNull())
    {
        logfile_write(csvFile, T1_log, T2_log, T3_log, T4_log, T5_log, T6_log,
                      Fan1_log, Fan2_log, Fan3_log, Fan4_log, wellstatus1_log, wellstatus2_log, tester_log);
        log_sec_time++;
        if(log_sec_time >= timer_log)
        {
            if(filepart<=2)
                oldfilename = csvFile;

            csvFile = oldfilename + QString(".part") + QString::number(filepart);
            logfile_write_title(csvFile);
            logfile_max();
            log_sec_time = 0;
            filepart++;
        }
    }

    if(!(PDfile.isNull()))
    {
        if(PD_draw_en == true && PD_timer == 2)
            PDfile_write(PDfile, time_log, ch1_log, ch2_log, ch3_log, ch4_log, ch5_log, ch6_log,
                     ch7_log, ch8_log, ch9_log, ch10_log, ch11_log, ch12_log);
    }

    if(!(Tempfile.isNull()))
    {
        if(Temp_draw_en)
            Tempfile_write(Tempfile, TempTime_log, T1_log, T2_log, T3_log, T4_log, T5_log, T6_log);
    }
}

void Widget::PD_draw(int cycleT)
{
    if(PD_draw_en)
    {
        if(PD_timer == 0)
            Command_LEDSW(true);
        else if(PD_timer == 1)
        {
            Command_PDGet();
        }
        else if(PD_timer == 2)
        {
            int x, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12;
            x = pointnum;
            y1 = qMin(int(PDch1*250/1024 + 20), 1024);
            y2 = qMin(int(PDch2*250/1024 + 20), 1024);
            y3 = qMin(int(PDch3*250/1024 + 20), 1024);
            y4 = qMin(int(PDch4*250/1024 + 20), 1024);
            y5 = qMin(int(PDch5*250/1024 + 20), 1024);
            y6 = qMin(int(PDch6*250/1024 + 20), 1024);
            y7 = qMin(int(PDch7*250/1024 + 20), 1024);
            y8 = qMin(int(PDch8*250/1024 + 20), 1024);
            y9 = 0;
            y10 = 0;
            y11 = 0;
            y12 = 0;
            PDdrawnewpoint(x, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12);
            pointnum++;
            if(pointnum>(PD_time/PDsamplerate))
                PD_draw_en = false;

            Command_LEDSW(false);
        }
        PD_timer += cycleT;
        if(PD_timer >= PDsamplerate)
            PD_timer = 0;
    }
}

void Widget::Temp_draw(int cycleT)
{
    int x, y1, y2, y3, y4, y5, y6;
    if(Temp_draw_en)
    {
        x = Temppointnum;
        y1 = qMin(int(real_temp1*2), 250);
        y2 = qMin(int(real_temp2*2), 250);
        y3 = qMin(int(real_temp3*2), 250);
        y4 = qMin(int(real_temp4*2), 250);
        y5 = qMin(int(real_temp5*2), 250);
        y6 = qMin(int(real_temp6*2), 250);

        Tempdrawnewpoint(x, y1, y2, y3, y4, y5, y6);
        Temppointnum+=cycleT;
        if(Temppointnum>300)
            Temp_draw_en = false;
    }
}

void Widget::Open_Device()
{
    if(!(serial_disconnect_timer))
        serialport_initial();
}
