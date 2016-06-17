#include "widget.h"
#include "ui_widget.h"

void Widget::num_input(bool sw, int num)
{
    int val = num;
    if(sw)
    {
        //val = (ui->lcdNumber_Heatingtime->intValue())*10 + val;
        if(val > heatingtime_max)
            val = heatingtime_max;
        ui->lcdNumber_Heatingtime->display(val);    
        //ui->lcdNumber_Heatingtime->setPalette(Qt::darkRed);
    }
    else
    {
        //val = (ui->lcdNumber_Targettemp->intValue())*10 + val;
        if(val > targettemp_max)
            val = targettemp_max;
        ui->lcdNumber_Targettemp->display(val);
        ui->lcdNumber_Targettemp->setPalette(Qt::darkRed);
    }
}

void Widget::num_temp(int num)
{
    int val = num;
    val = (ui->lcdNumber_num->intValue())*10 + val;
    ui->lcdNumber_num->display(val);
}
