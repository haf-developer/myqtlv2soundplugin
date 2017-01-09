#include "soundlv2lib.h"


int Soundlv2lib::initialized=0;

Soundlv2lib::Soundlv2lib()
{
}

int Soundlv2lib::Init()
{
    ++initialized;
    return initialized;
}
