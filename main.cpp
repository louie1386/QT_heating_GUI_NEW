#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = w.palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/Icon/metal1.jpg").scaled( // 缩放背景图.
                             w.size(),
                             Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation))); // 使用平滑的缩放方式
    w.setPalette(palette); // 至此, 已给widget加上了背景图.
    //w.showFullScreen();
    w.show();

    return a.exec();
}
