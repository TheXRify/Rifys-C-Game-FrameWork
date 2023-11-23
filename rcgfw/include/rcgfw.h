#ifndef RCGFW_H
#define RCGFW_H

#define RCGFW_FALSE 0
#define RCGFW_TRUE 1

#include "types.h"

// initialize the engine (create a window, etc..)
void rcgfwInit(RCGFWstate *state, const char *title, const RCGFWuint width, const RCGFWuint height);

// clean up the engine's dynamically allocated memory (prevent memory leaks)
void rcgfwClose(RCGFWstate *state);

#include "display.h"

#endif