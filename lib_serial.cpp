#include "widget.h"
#include "ui_widget.h"

void Widget::read_Com()
{
    QByteArray RXD_str;

    RXD_str.clear();
    RXD_str = serial.read(1).toHex();

    while(!RXD_str.isEmpty())
    {
        int RXD_buff = RXD_str.toInt(0,16);
        if(RXD_buff == command_tag && RXD_counter == 0)
        {
            //RXD_counter = 0;
            RXD_length = 0;
            RXD_cks = 0;
            comm_num = 0;
        }
        else if(RXD_counter == 1)
        {
            RXD_length = RXD_buff;
        }
        else if(RXD_counter == (RXD_length + 1))
        {
            if((RXD_cks + RXD_buff)%0x100 == 0)
            {
                Command_run(command);
            }
            else
            {

            }
            RXD_counter = -1;
            comm_num = 0;
        }
        else
        {
            command[comm_num] = RXD_buff;
            RXD_cks = (RXD_cks + RXD_buff)% 0x100;
            comm_num++;
        }
        RXD_counter++;
        RXD_str = serial.read(1).toHex();
    }

}
