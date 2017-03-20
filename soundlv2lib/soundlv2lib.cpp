#include "soundlv2lib.h"
#include <assert.h>

int Soundlv2lib::initialized=0;
int Soundlv2lib::p_initialization=0;
Soundlv2lib* Soundlv2lib::p_instance=0;

Soundlv2lib::Soundlv2lib()
{
    post_initialization = p_initialization;
}

Soundlv2lib::~Soundlv2lib()
{

}

Soundlv2lib &Soundlv2lib::Instance()
{
    Soundlv2lib *new_instance;
    if( p_initialization==0 )
    {
        p_initialization++;
        try
        {
            new_instance=new Soundlv2lib();
        }
        catch( ... ) //Catch memory allocation  exception, clean the mess and throw again.
        {
            //QT_RETHROW

        }

        // It is still possible that other thread started initialization
        // but could not yet finish it. Thus object is still null.
        if(new_instance->post_initialization == p_initialization )
        {
            p_instance = new_instance;
        }
        else
        {
            // Now other thread(s) has also created object.
            // TODO
            // Have to decide which one is valid and delete others.
        }
    }
    return *p_instance;
}


int Soundlv2lib::Init()
{
    //Simple single thread test for correctly constructed object.
    //This test should fail when multiple threads tries to get first
    //instance in the same time.
    assert(post_initialization == 1);

    ++initialized;
    return initialized;
}
