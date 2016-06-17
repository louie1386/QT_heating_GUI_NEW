#include "widget.h"
#include "ui_widget.h"

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::Paint)
    {
        //QColor orange = QColor(255, 100, 0);

        if(obj == ui->widget_DrawIn)
        {
            QPainter painter(ui->widget_DrawIn);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,PD_time/PDsamplerate*PDdisplayPointsec,275);

            if(ui->checkBox_PD_1->isChecked())
            {
                painter.setPen(Qt::red);
                painter.drawPolyline(points_1, pointnum);
            }

            if(ui->checkBox_PD_2->isChecked())
            {
                painter.setPen(Qt::darkRed);
                painter.drawPolyline(points_2, pointnum);
            }

            if(ui->checkBox_PD_3->isChecked())
            {
                painter.setPen(Qt::darkYellow);
                painter.drawPolyline(points_3, pointnum);
            }

            if(ui->checkBox_PD_4->isChecked())
            {
                painter.setPen(Qt::green);
                painter.drawPolyline(points_4, pointnum);
            }

            if(ui->checkBox_PD_5->isChecked())
            {
                painter.setPen(Qt::darkGreen);
                painter.drawPolyline(points_5, pointnum);
            }

            if(ui->checkBox_PD_6->isChecked())
            {
                painter.setPen(Qt::blue);
                painter.drawPolyline(points_6, pointnum);
            }

            if(ui->checkBox_PD_7->isChecked())
            {
                painter.setPen(Qt::darkBlue);
                painter.drawPolyline(points_7, pointnum);
            }

            if(ui->checkBox_PD_8->isChecked())
            {
                painter.setPen(Qt::black);
                painter.drawPolyline(points_8, pointnum);
            }

            if(ui->checkBox_PD_9->isChecked())
            {
                painter.setPen(Qt::white);
                painter.drawPolyline(points_9, pointnum);
            }

            if(ui->checkBox_PD_10->isChecked())
            {
                painter.setPen(Qt::white);
                painter.drawPolyline(points_10, pointnum);
            }

            if(ui->checkBox_PD_11->isChecked())
            {
                painter.setPen(Qt::white);
                painter.drawPolyline(points_11, pointnum);
            }

            if(ui->checkBox_PD_12->isChecked())
            {
                painter.setPen(Qt::white);
                painter.drawPolyline(points_12, pointnum);
            }
        }
        else if(obj == ui->widget_TempDisplay)
        {
            QPainter painter(ui->widget_TempDisplay);
            painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter.setPen(Qt::black);
            painter.drawRect(0,0,300,250);

            if(ui->checkBox_Temp_1->isChecked())
            {
                painter.setPen(Qt::red);
                painter.drawPolyline(TempPF1, Temppointnum);
            }

            if(ui->checkBox_Temp_2->isChecked())
            {
                painter.setPen(Qt::blue);
                painter.drawPolyline(TempPF2, Temppointnum);
            }

            if(ui->checkBox_Temp_3->isChecked())
            {
                painter.setPen(Qt::black);
                painter.drawPolyline(TempPF3, Temppointnum);
            }

            if(ui->checkBox_Temp_4->isChecked())
            {
                painter.setPen(Qt::gray);
                painter.drawPolyline(TempPF4, Temppointnum);
            }

            if(ui->checkBox_Temp_5->isChecked())
            {
                painter.setPen(Qt::green);
                painter.drawPolyline(TempPF5, Temppointnum);
            }

            if(ui->checkBox_Temp_6->isChecked())
            {
                painter.setPen(Qt::magenta);
                painter.drawPolyline(TempPF6, Temppointnum);
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::PDdrawnewpoint(int x, int y1, int y2, int y3, int y4, int y5, int y6,
                            int y7, int y8, int y9, int y10, int y11, int y12)
{
    int Height = ui->widget_DrawIn->height();
    points_1[x] = QPointF(x*PDdisplayPointsec, Height - y1);
    points_2[x] = QPointF(x*PDdisplayPointsec, Height - y2);
    points_3[x] = QPointF(x*PDdisplayPointsec, Height - y3);
    points_4[x] = QPointF(x*PDdisplayPointsec, Height - y4);
    points_5[x] = QPointF(x*PDdisplayPointsec, Height - y5);
    points_6[x] = QPointF(x*PDdisplayPointsec, Height - y6);
    points_7[x] = QPointF(x*PDdisplayPointsec, Height - y7);
    points_8[x] = QPointF(x*PDdisplayPointsec, Height - y8);
    points_9[x] = QPointF(x*PDdisplayPointsec, Height - y9);
    points_10[x] = QPointF(x*PDdisplayPointsec, Height - y10);
    points_11[x] = QPointF(x*PDdisplayPointsec, Height - y11);
    points_12[x] = QPointF(x*PDdisplayPointsec, Height - y12);

    ui->widget_DrawIn->update();
}

void Widget::Tempdrawnewpoint(int x, int y1, int y2, int y3, int y4, int y5, int y6)
{
    int Height = ui->widget_TempDisplay->height();
    TempPF1[x] = QPointF(x, Height - y1);
    TempPF2[x] = QPointF(x, Height - y2);
    TempPF3[x] = QPointF(x, Height - y3);
    TempPF4[x] = QPointF(x, Height - y4);
    TempPF5[x] = QPointF(x, Height - y5);
    TempPF6[x] = QPointF(x, Height - y6);

    ui->widget_TempDisplay->update();
}
