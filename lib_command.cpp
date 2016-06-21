#include "widget.h"
#include "ui_widget.h"

void Widget::Command_run(int *com)
{
    int opcode = com[0];
    serial_disconnect_timer = SerialResetTime;

    if(opcode == (opcode_readstatus + opcode_ret_base))
    {
        real_temp1 = double(com[1]) + (double(com[2])/10);
        ui->lcdNumber_temp_1->display(real_temp1);

        real_temp2 = double(com[3]) + (double(com[4])/10);
        ui->lcdNumber_temp_2->display(real_temp2);

        real_temp3 = double(com[5]) + (double(com[6])/10);
        ui->lcdNumber_temp_3->display(real_temp3);

        real_temp4 = double(com[7]) + (double(com[8])/10);
        ui->lcdNumber_temp_4->display(real_temp4);

        real_temp5 = double(com[9]) + (double(com[10])/10);
        ui->lcdNumber_temp_5->display(real_temp5);

        real_temp6 = double(com[11]) + (double(com[12])/10);
        ui->lcdNumber_temp_6->display(real_temp6);

        Fan1 = int(com[13]);
        ui->lcdNumber_Fan_1->display(Fan1);

        Fan2 = int(com[14]);
        ui->lcdNumber_Fan_2->display(Fan2);

        Fan3 = int(com[15]);
        ui->lcdNumber_Fan_3->display(Fan3);

        Fan4 = int(com[16]);
        ui->lcdNumber_Fan_4->display(Fan4);

        trigger_point_1 = com[17];
        trigger_point_2 = com[18];

        int well_lu_1 = 0xFF;
        int well_lu_2 = 0xFF;

        ui->lcdNumber_RealTemp->display(real_temp1);

        if(heating_en)
        {
            if(char_to_QBitArray(trigger_point_1).testBit(0))
            {
                if(well_timer[0] == (-1))
                {
                    LED_red(PB_LED_1);
                    well_timer[0] = Heating_Time;
                }
                else if(well_timer[0] == (-2))
                {
                    well_lu_1 &= 0xFE;  // 11111110b
                }
            }
            if(char_to_QBitArray(trigger_point_1).testBit(1))
            {
                if(well_timer[1] == (-1))
                {
                    LED_red(PB_LED_2);
                    well_timer[1] = Heating_Time;
                }
                else if(well_timer[1] == (-2))
                {
                    well_lu_1 &= 0xFD;  // 11111101b
                }
            }
            if(char_to_QBitArray(trigger_point_1).testBit(2))
            {
                if(well_timer[2] == (-1))
                {
                    LED_red(PB_LED_3);
                    well_timer[2] = Heating_Time;
                }
                else if(well_timer[2] == (-2))
                {
                    well_lu_1 &= 0xFB;  // 11111011b
                }
            }
            if(char_to_QBitArray(trigger_point_1).testBit(3))
            {
                if(well_timer[3] == (-1))
                {
                    LED_red(PB_LED_4);
                    well_timer[3] = Heating_Time;
                }
                else if(well_timer[3] == (-2))
                {
                    well_lu_1 &= 0xF7;  // 11110111bc
                }
            }
            if(char_to_QBitArray(trigger_point_1).testBit(4))
            {
                if(well_timer[4] == (-1))
                {
                    LED_red(PB_LED_5);
                    well_timer[4] = Heating_Time;
                }
                else if(well_timer[4] == (-2))
                {
                    well_lu_1 &= 0xEF;  // 11101111b
                }
            }
            if(char_to_QBitArray(trigger_point_1).testBit(5))
            {
                if(well_timer[5] == (-1))
                {
                    LED_red(PB_LED_6);
                    well_timer[5] = Heating_Time;
                }
                else if(well_timer[5] == (-2))
                {
                    well_lu_1 &= 0xDF;  // 11011111b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(0))
            {
                if(well_timer[6] == (-1))
                {
                    LED_red(PB_LED_7);
                    well_timer[6] = Heating_Time;
                }
                else if(well_timer[6] == (-2))
                {
                    well_lu_2 &= 0xFE;  // 11111110b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(1))
            {
                if(well_timer[7] == (-1))
                {
                    LED_red(PB_LED_8);
                    well_timer[7] = Heating_Time;
                }
                else if(well_timer[7] == (-2))
                {
                    well_lu_2 &= 0xFD;  // 11111101b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(2))
            {
                if(well_timer[8] == (-1))
                {
                    LED_red(PB_LED_9);
                    well_timer[8] = Heating_Time;
                }
                else if(well_timer[8] == (-2))
                {
                    well_lu_2 &= 0xFB;  // 11111011b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(3))
            {
                if(well_timer[9] == (-1))
                {
                    LED_red(PB_LED_10);
                    well_timer[9] = Heating_Time;
                }
                else if(well_timer[9] == (-2))
                {
                    well_lu_2 &= 0xF7;  // 11110111b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(4))
            {
                if(well_timer[10] == (-1))
                {
                    LED_red(PB_LED_11);
                    well_timer[10] = Heating_Time;
                }
                else if(well_timer[10] == (-2))
                {
                    well_lu_2 &= 0xEF;  // 11101111b
                }
            }
            if(char_to_QBitArray(trigger_point_2).testBit(5))
            {
                if(well_timer[11] == (-1))
                {
                    LED_red(PB_LED_12);
                    well_timer[11] = Heating_Time;
                }
                else if(well_timer[11] == (-2))
                {
                    well_lu_2 &= 0xDF;  // 11011111b
                }
            }

            //if((well_lu_1 != 0xFF) || (well_lu_2 != 0xFF))
            //    Command_LiftUp(well_lu_1, well_lu_2);
        }
    }
    else if(opcode == (opcode_writesetting + opcode_ret_base))
    {


    }
    else if(opcode == (opcode_pdget + opcode_ret_base))
    {
        PDch1 = (com[1]*0xFF + com[2]);
        PDch2 = (com[3]*0xFF + com[4]);
        PDch3 = (com[5]*0xFF + com[6]);
        PDch4 = (com[7]*0xFF + com[8]);
        PDch5 = (com[9]*0xFF + com[10]);
        PDch6 = (com[11]*0xFF + com[12]);
        PDch7 = (com[13]*0xFF + com[14]);
        PDch8 = (com[15]*0xFF + com[16]);
        PDch9 = 0;
        PDch10 = 0;
        PDch11 = 0;
        PDch12 = 0;
    }
    else if(opcode == (opcode_verget + opcode_ret_base))
    {
        QString ArduinoVersion_Main, ArduinoVersion_Sub, ArduinoVersion_Debug, ArduinoVersion, point;
        ArduinoVersion_Main.setNum(com[1]);
        ArduinoVersion_Sub.setNum(com[2]);
        ArduinoVersion_Debug.setNum(com[3]);
        point = QString(".");
        if(com[1]<10)
            ArduinoVersion_Main.insert(0,"0");
        if(com[2]<10)
            ArduinoVersion_Sub.insert(0,"0");
        if(com[3]<10)
            ArduinoVersion_Debug.insert(0,"0");
        ArduinoVersion = ArduinoVersion_Main + point + ArduinoVersion_Sub + point + ArduinoVersion_Debug;
        ui->label_Arduino_Version->setText(ArduinoVersion);
    }
    else if(opcode == opcode_tester)
    {
        tester = double(com[1]) + (double(com[2])/10);
        ui->lcdNumber_Test->display(tester);
    }
}

QBitArray Widget::char_to_QBitArray(char input)
{
    QBitArray ret(8);

    ret[0] = input & 1;
    ret[1] = input & 2;
    ret[2] = input & 4;
    ret[3] = input & 8;
    ret[4] = input & 16;
    ret[5] = input & 32;
    ret[6] = input & 64;
    ret[7] = input & 128;

    return ret;
}

void Widget::Command_ReadStatus()
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x02;
    TXD_str += char(opcode_readstatus);
    chksum = 0x100 - ((opcode_readstatus) % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_WriteSetting(int Temp_int, int Temp_deg)
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x04;
    TXD_str += char(opcode_writesetting);
    TXD_str += char(Temp_int);
    TXD_str += char(Temp_deg);
    chksum = 0x100 - ((opcode_writesetting + Temp_int + Temp_deg) % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_LiftUp(int liftup_1, int liftup_2)
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x04;
    TXD_str += char(opcode_liftup);
    TXD_str += char(liftup_1);
    TXD_str += char(liftup_2);
    chksum = 0x100 - ((opcode_liftup + liftup_1 + liftup_2) % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_LEDSW(bool ONOFF)
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x03;
    TXD_str += char(opcode_ledsw);
    TXD_str += char(ONOFF);
    chksum = 0x100 - ((opcode_ledsw + ONOFF) % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_PDGet()
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x02;
    TXD_str += char(opcode_pdget);
    chksum = 0x100 - (opcode_pdget % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_VerGet()
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x02;
    TXD_str += char(opcode_verget);
    chksum = 0x100 - (opcode_verget % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}

void Widget::Command_Tester()
{
    QString TXD_str;
    int chksum;

    TXD_str += char(command_tag);
    TXD_str += 0x02;
    TXD_str += char(opcode_tester);
    chksum = 0x100 - (opcode_tester % 0x100);
    TXD_str += char(chksum);
    serial.write(TXD_str.toLatin1());
}
