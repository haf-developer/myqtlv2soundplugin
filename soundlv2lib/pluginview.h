#ifndef PLUGINVIEW_H
#define PLUGINVIEW_H

#include <QPixmap>
#include <QWidget>
#include <QBitmap>

class PluginView : public QWidget
{
    Q_OBJECT
public:
    explicit PluginView(QWidget *parent = 0);

signals:

public slots:

protected:
    QPixmap *testmap;
    QBitmap *testmask;
    void paintEvent(QPaintEvent *paintevent) override;
};

#endif // PLUGINVIEW_H
