#include "rcgfw.h"

#include <stdio.h>
#include <stdlib.h>

void _rcgfw_critical_error()
{
    rcgfwClose();
    exit(-1);
}

void _rcgfw_checkError(RCGFWbool condition, const char *msg, void (*callback)())
{
    if(condition)
    {
        printf("%s\n", msg);
        (*callback)();
    }
}

void _rcgfw_checkDisplayError(RCGFWbool condition, const char *msg, RCGFWdisplay *display, void (*callback)(RCGFWdisplay *display))
{
    if(condition)
    {
        printf("%s\n", msg);
        (*callback)(display);
    }
}