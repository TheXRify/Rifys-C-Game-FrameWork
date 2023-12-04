#include "rcgfw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

struct rcgfw_state
{
    RCGFWdisplay *display;
    RCGFWshader *shaders;
    RCGFWu32 *shaderPtr;
    RCGFWshaderProgram program;
};

RCGFWstate state;

extern void _rcgfw_attach_shader(void *shdrOffset, int program);

void _rcgfw_add_shader(RCGFWshader shader);









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

    rcgfwCreateShader("vertex", RCGFW_VERTEX_SHADER);
    rcgfwCreateShader("fragment", RCGFW_FRAGMENT_SHADER);

    state.program = rcgfwCreateProgram();
    _rcgfw_attach_shader((void*) 0, state.program);
    _rcgfw_attach_shader((void*) 1, state.program);
}

/*
    Clean up all of the allocated memory that the engine has created.
    Terminate GLFW and destroy GLFW window.
*/
void rcgfwClose(void)
{
    rcgfwDestroyProgram();
    free(state.shaders);
    state.shaders = NULL;
    state.shaderPtr = NULL;
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
    size_t size = RCGFW_ARR_SIZE(state.shaders) - 1;
    size_t sizeBytes = sizeof(state.shaders);
    if(state.shaderPtr >= &state.shaders[size])
    {
        state.shaders = realloc(state.shaders, sizeBytes * 2);
    }

    (*state.shaderPtr) = shader;
    state.shaderPtr++;
}

RCGFWshader _rcgfw_get_shader(void *offset)
{
    static int *shader;
    shader = (state.shaders + (*(int*)(&offset)));
    return *shader;
}

RCGFWshader *_rcgfw_get_shader_ptr(void *offset)
{
    return (state.shaders + (*(int*)(&offset)));
}

RCGFWshaderProgram _rcgfw_get_shader_program(void)
{
    return state.program;
}

size_t _rcgfw_get_num_shaders(void)
{
    return RCGFW_ARR_SIZE(state.shaders);
}