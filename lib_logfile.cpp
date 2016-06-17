#include "widget.h"
#include "ui_widget.h"

QString Widget::FileName_Setting(QString FileName)
{
    QDateTime Now;
    QString logfilename;

    logfilename = Now.currentDateTime().toString();
    logfilename.replace(" ", "_");
    logfilename.replace(":", "_");
    logfilename += "_";
    logfilename += FileName;

    return logfilename;
}

QString Widget::logfile_setting(QString Path, QString FileName)
{
    QString cddir = "/";
    QString Real_Path;
    QString Devicedir;
    QStringList DeviceName;
    uint filenum;

    QString logfilename = FileName_Setting(FileName);

    if(QDir(logPath).exists())
    {
        logdir.setCurrent(logPath);
        logdir.setSorting(QDir::Time);
        DeviceName = logdir.entryList();
        filenum = logdir.count();
        if(filenum > 2)
        {
            Devicedir = DeviceName[filenum-1];
            logdir.mkpath(Devicedir + cddir + Path);
            logdir.setCurrent(logdir.currentPath() + cddir + Devicedir + cddir + Path);
            Real_Path = logdir.currentPath() + cddir + logfilename;
        }
        else
        {
            logdir.setCurrent(locationdir);
            logdir.mkpath(Path);
            logdir.setCurrent(logdir.currentPath() + cddir + Path);
            Real_Path = logdir.currentPath() + cddir + logfilename;
        }
    }
    else
    {
        logdir.setCurrent(locationdir);
        logdir.mkpath(Path);
        logdir.setCurrent(logdir.currentPath() + cddir + Path);
        Real_Path = logdir.currentPath() + cddir + logfilename;
    }
    logfile_max();

    return Real_Path;
}

void Widget::logfile_max()
{
    QString Devicedir;
    QStringList DeviceName;
    uint filenum;

    filenum = logdir.count();
    DeviceName = logdir.entryList();
    if(filenum > (logfilemax + 2))
    {
        Devicedir = DeviceName[2];
        logdir.remove(Devicedir);
    }
}

void Widget::logfile_write(QString file, QByteArray T1_log, QByteArray T2_log, QByteArray T3_log,
                           QByteArray T4_log, QByteArray T5_log, QByteArray T6_log,
                           QByteArray Fan1_log, QByteArray Fan2_log, QByteArray Fan3_log, QByteArray Fan4_log,
                           QByteArray wellstatus1_log, QByteArray wellstatus2_log, QByteArray tester)
{
    QFile writefile;
    writefile.setFileName(file);
    if(writefile.open(QIODevice::Append))
    {
        writefile.write(T1_log.data());
        writefile.write(",");
        writefile.write(T2_log.data());
        writefile.write(",");
        writefile.write(T3_log.data());
        writefile.write(",");
        writefile.write(T4_log.data());
        writefile.write(",");
        writefile.write(T5_log.data());
        writefile.write(",");
        writefile.write(T6_log.data());
        writefile.write(",");
        writefile.write(Fan1_log.data());
        writefile.write(",");
        writefile.write(Fan2_log.data());
        writefile.write(",");
        writefile.write(Fan3_log.data());
        writefile.write(",");
        writefile.write(Fan4_log.data());
        writefile.write(",");
        writefile.write(wellstatus1_log.data());
        writefile.write(",");
        writefile.write(wellstatus2_log.data());
        writefile.write(",");
        writefile.write(tester.data());
        writefile.write("\n");
        writefile.close();
    }
}

void Widget::logfile_write_title(QString file)
{
    logfile_write(file, "T1(Heater)", "T2", "T3", "T4", "T5", "T6",
                  "Fan1", "Fan2", "Fan3", "Fan4", "Well Status(well 1~6)", "Well Status(well 7~12)", "Test Data");
}

void Widget::PDfile_write(QString file, QByteArray time,
                          QByteArray ch1, QByteArray ch2, QByteArray ch3, QByteArray ch4,
                          QByteArray ch5, QByteArray ch6, QByteArray ch7, QByteArray ch8,
                          QByteArray ch9, QByteArray ch10, QByteArray ch11, QByteArray ch12)
{
    QFile writefile;
    writefile.setFileName(file);
    if(writefile.open(QIODevice::Append))
    {
        writefile.write(time.data());
        writefile.write(",");
        writefile.write(ch1.data());
        writefile.write(",");
        writefile.write(ch2.data());
        writefile.write(",");
        writefile.write(ch3.data());
        writefile.write(",");
        writefile.write(ch4.data());
        writefile.write(",");
        writefile.write(ch5.data());
        writefile.write(",");
        writefile.write(ch6.data());
        writefile.write(",");
        writefile.write(ch7.data());
        writefile.write(",");
        writefile.write(ch8.data());
        writefile.write(",");
        writefile.write(ch9.data());
        writefile.write(",");
        writefile.write(ch10.data());
        writefile.write(",");
        writefile.write(ch11.data());
        writefile.write(",");
        writefile.write(ch12.data());
        writefile.write("\n");
        writefile.close();
    }
}

void Widget::PDfile_write_title(QString file)
{
    PDfile_write(file, "Time", "ch1", "ch2", "ch3", "ch4", "ch5", "ch6",
                  "ch7", "ch8", "ch9", "ch10", "ch11", "ch12");
}

void Widget::Tempfile_write(QString file, QByteArray time,
                          QByteArray TP1, QByteArray TP2, QByteArray TP3, QByteArray TP4,
                          QByteArray TP5, QByteArray TP6)
{
    QFile writefile;
    writefile.setFileName(file);
    if(writefile.open(QIODevice::Append))
    {
        writefile.write(time.data());
        writefile.write(",");
        writefile.write(TP1.data());
        writefile.write(",");
        writefile.write(TP2.data());
        writefile.write(",");
        writefile.write(TP3.data());
        writefile.write(",");
        writefile.write(TP4.data());
        writefile.write(",");
        writefile.write(TP5.data());
        writefile.write(",");
        writefile.write(TP6.data());
        writefile.write("\n");
        writefile.close();
    }
}

void Widget::Tempfile_write_title(QString file)
{
    Tempfile_write(file, "Time", "Temp1", "Temp2", "Temp3", "Temp4", "Temp5", "Temp6");
}
