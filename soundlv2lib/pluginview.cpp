#include "pluginview.h"

#include <QPainter>
#include <QTime>
#include <QTimer>


PluginView::PluginView(QWidget *parent) : QWidget(parent)
{
    typedef void (QWidget::*WidgetUpdateSlot)();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, static_cast<WidgetUpdateSlot>(&QWidget::update));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock"));
    resize(200, 200);

    testmap = new QPixmap(100,100);
    testmap->fill(Qt::darkYellow);
    testmask = new QBitmap(100,100);
    testmask->fill(Qt::color1);
}

void PluginView::paintEvent(QPaintEvent *paintevent)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -100)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(255, 127, 127, 191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    //painter.translate(width() / 2, height() / 4);
    painter.scale(side / 200.0, side / 200.0);

    //painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j)
    {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    QPainter maskPaint(testmask);
    QColor alphablack(100, 100, 255, 127);
    QColor fullblack(0, 255, 0, 255);

    QPen maskpen(fullblack, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    maskPaint.setPen(maskpen);
    maskPaint.drawLine(50,0,time.second(),time.second()); //This is not shown
    maskPaint.drawRect(3,3,94,94);
    maskPaint.drawLine(1,1,39+time.second(),89);
    testmap->setMask(*testmask);

    painter.rotate(6*time.second());
    painter.drawPixmap(50-time.second(),50-time.second(), *testmap);
    QPainter pixPaint(testmap);

    QPen pen(alphablack, 2, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    pixPaint.setBackgroundMode( Qt::OpaqueMode );
    pixPaint.setPen(pen);
    pixPaint.drawLine(0,0,40+time.second(),90);
}
