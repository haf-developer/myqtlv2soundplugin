#ifndef SOUNDLV2LIB_H
#define SOUNDLV2LIB_H

#include "soundlv2lib_global.h"

class SOUNDLV2LIBSHARED_EXPORT Soundlv2lib
{
static int initialized;
public:
    Soundlv2lib();
    int Init();
};

#endif // SOUNDLV2LIB_H
