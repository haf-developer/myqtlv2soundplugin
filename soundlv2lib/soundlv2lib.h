#ifndef SOUNDLV2LIB_H
#define SOUNDLV2LIB_H

#include "soundlv2lib_global.h"

/*
 * This class is singleton because it acts as plugin container.
 * Lazy initialization so it requires guards if multiple threads
 * tries to create instance at the same time.
 * Threads can read others plugin data but only the thread that
 * owns the plugin should be able to write input data for plugin.
 * TODO
 * This could be possible future optimization. If plugins could
 * write their output data directly to other threads input data.
 * Think like car engine sound plugin output data is passed directly
 * to tunnel echo plugin input data.
 * Current implementation requires tunnel echo plugin thread to read
 * engine plugin data as input. But maeby this optimization requires
 * too much and gains are too little.
 */
class SOUNDLV2LIBSHARED_EXPORT Soundlv2lib
{
public:
    static Soundlv2lib& Instance();
    int Init();

private:
    static int initialized;
    static int p_initialization; //Guard for threads
    int post_initialization;
    static Soundlv2lib *p_instance;
    Soundlv2lib();
    ~Soundlv2lib();
};

#endif // SOUNDLV2LIB_H
