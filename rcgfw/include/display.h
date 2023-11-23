#ifndef RCGFW_DISPLAY_H
#define RCGFW_DISPLAY_H

#include "types.h"

// create a display created by glfw
RCGFWdisplay *rcgfwCreateDisplay(const char *title, RCGFWuint width, RCGFWuint height);

// destroy a display created by glfw
void rcgfwDestroyDisplay(RCGFWdisplay *display);

void rcgfwDisplayClear(float r, float g, float b);
void rcgfwDisplayShow(RCGFWstate *state);

#endif