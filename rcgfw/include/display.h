#ifndef RCGFW_DISPLAY_H
#define RCGFW_DISPLAY_H

#include "defs.h"
#include "types.h"

/* window creation */
void rcgfwDefaultDisplayProperties(RCGFWdisplayProps *props);
RCGFWdisplay *rcgfwCreateDisplay(RCGFWdisplayProps props);
void rcgfwDestroyDisplay(RCGFWdisplay *display);

RCGFWbool rcgfwDisplayShouldClose(void);
void rcgfwDisplaySwap(void);
void rcgfwDisplayClear(RCGFWcolor color);

#endif