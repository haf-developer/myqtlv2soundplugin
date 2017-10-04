#ifndef SOUNDLV2QTHOST_H
#define SOUNDLV2QTHOST_H

#include <QObject>
#include <QSharedDataPointer>

#include <lv2.h>

//#include <lilv.h>
#include "lilv-0/lilv/lilv.h"


class Soundlv2QtHostData;

class Soundlv2QtHost : public QObject
{
    Q_OBJECT
public:
    explicit Soundlv2QtHost(QObject *parent = 0);
    Soundlv2QtHost(const Soundlv2QtHost &);
    Soundlv2QtHost &operator=(const Soundlv2QtHost &);
    ~Soundlv2QtHost();
    QString infohostapi();
signals:

public slots:

private:
    QSharedDataPointer<Soundlv2QtHostData> data;
};

#endif // SOUNDLV2QTHOST_H
