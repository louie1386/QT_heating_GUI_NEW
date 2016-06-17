#include "widget.h"
#include "ui_widget.h"

void Widget::LED_heating_en()
{
    LED_green(PB_LED_1);
    LED_green(PB_LED_2);
    LED_green(PB_LED_3);
    LED_green(PB_LED_4);
    LED_green(PB_LED_5);
    LED_green(PB_LED_6);
    LED_green(PB_LED_7);
    LED_green(PB_LED_8);
    LED_green(PB_LED_9);
    LED_green(PB_LED_10);
    LED_green(PB_LED_11);
    LED_green(PB_LED_12);
}

void Widget::progressbar_update(QProgressBar *PB, int well_time, double TP)
{
    if(well_time>=0)
    {
        PB->setValue(100 - (well_time/TP));
    }
}

void Widget::LED_yellow(QPushButton *PB)
{
    PB->setIcon(QIcon(YellowLED));
    PB->setCursor(Qt::PointingHandCursor);
}

void Widget::LED_red(QPushButton *PB)
{
    PB->setIcon(QIcon(RedLED));
    PB->setCursor(Qt::WaitCursor);
}

void Widget::LED_green(QPushButton *PB)
{
    PB->setIcon(QIcon(GreenLED));
    PB->setCursor(Qt::WhatsThisCursor);
}

void Widget::LED_blue(QPushButton *PB)
{
    PB->setIcon(QIcon(BlueLED));
}

void Widget::LED_orange(QPushButton *PB)
{
    PB->setIcon(QIcon(OrangeLED));
}
