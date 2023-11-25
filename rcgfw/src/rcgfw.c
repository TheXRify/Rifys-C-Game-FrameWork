#include "rcgfw.h"

#include <stdlib.h>

struct rcgfw_state
{
    RCGFWbool running; // deprecated : user creates running variable.
    RCGFWdisplay *display;
};

RCGFWstate state;












/*
   Initialize the engine and all opengl boilerplate
   Does not link or use shader pogram!!!!
*/
void rcgfwInit(RCGFWdisplayProps props)
{
    state.display = rcgfwCreateDisplay(props);
}

/*
    Clean up all of the allocated memory that the engine has created.
    Terminate GLFW and destroy GLFW window.
*/
void rcgfwClose(void)
{
    rcgfwDestroyDisplay(state.display);
    exit(0);
}

/* internal functions */
RCGFWdisplay *_rcgfw_getDisplay(RCGFWstate *state)
{
    return state->display;
}