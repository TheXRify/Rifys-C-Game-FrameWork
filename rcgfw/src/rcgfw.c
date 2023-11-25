#include "rcgfw.h"

#include <stdlib.h>

struct rcgfw_state
{
    RCGFWbool running; // deprecated : user creates running variable.
};

static RCGFWstate state;












 /*
    Initialize the engine and all opengl boilerplate
    Does not link or use shader pogram!!!!
 */
void rcgfwInit(void)
{
    
}

/*
    Clean up all of the allocated memory that the engine has created.
    Terminate GLFW and destroy GLFW window.
*/
void rcgfwClose(void)
{
    exit(0);
}