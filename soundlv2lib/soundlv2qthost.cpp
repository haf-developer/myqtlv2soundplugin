#include "soundlv2qthost.h"

class Soundlv2QtHostData : public QSharedData
{
public:

};

Soundlv2QtHost::Soundlv2QtHost(QObject *parent) : QObject(parent), data(new Soundlv2QtHostData)
{

}

Soundlv2QtHost::Soundlv2QtHost(const Soundlv2QtHost &rhs) : data(rhs.data)
{

}

Soundlv2QtHost &Soundlv2QtHost::operator=(const Soundlv2QtHost &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Soundlv2QtHost::~Soundlv2QtHost()
{

}

QString Soundlv2QtHost::infohostapi()
{
    return QString(LILV_NS_LILV);
    //return QString(LILV_VERSION);
}
