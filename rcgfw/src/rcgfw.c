#include "rcgfw.h"

#include "display.h"

void rcgfwInit(RCGFWstate *state, const char *title, const RCGFWuint width, const RCGFWuint height)
{
    state->display = rcgfwCreateDisplay(title, width, height);
    state->running = RCGFW_FALSE;
}

void rcgfwClose(RCGFWstate *state)
{
    rcgfwDestroyDisplay(state->display);
    state->running = RCGFW_FALSE;
}