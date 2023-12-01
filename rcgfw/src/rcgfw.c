#include "rcgfw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rcgfw_state
{
    RCGFWdisplay *display;
    RCGFWshader *shaders;
    RCGFWu32 *shaderPtr;
    RCGFWshaderProgram program;
};

RCGFWstate state;












/*
   Initialize the engine and all opengl boilerplate
   Does not link or use shader pogram!!!!
*/
void rcgfwInit(RCGFWdisplayProps props)
{
    state.display = rcgfwCreateDisplay(props);
    state.shaders = malloc(2 * sizeof(int));
    memset(state.shaders, 0, sizeof(state.shaders) / sizeof(int));
    state.shaderPtr = state.shaders;
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

void _rcgfw_add_shader(RCGFWshader shader)
{
    // (*state.shaderPtr) = shader;
    // state.shaderPtr ++;

    // size_t size = RCGFW_ARR_SIZE(state.shaders) - 1;
    // if(state.shaderPtr >= &state.shaders[size])
    // {
    //     state.shaders = realloc(state.shaders, sizeof(state.shaders) + (2 * sizeof(int)));
    // }

    size_t size = RCGFW_ARR_SIZE(state.shaders) - 1;
    size_t sizeBytes = sizeof(state.shaders);
    if(state.shaderPtr >= &state.shaders[size])
    {
        state.shaders = realloc(state.shaders, sizeBytes * 2);
    }

    (*state.shaderPtr) = shader;
    state.shaderPtr++;
}

int _rcgfw_get_shader(void *offset)
{
    static int *shader;
    shader = (state.shaders + (*(int*)(&offset)));
    return *shader;
}