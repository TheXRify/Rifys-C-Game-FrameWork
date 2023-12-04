#include "display.h"

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define _RCGFW_WINDOW_HINTS glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); \
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); \
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)

struct rcgfw_display
{
    unsigned int width, height;
    char *title;
    GLFWwindow *handle;
};

extern RCGFWdisplay *_rcgfw_getDisplay(RCGFWstate *state);
extern void _rcgfw_checkDisplayError(RCGFWbool condition, const char *msg, RCGFWdisplay *display, void (*callback)());
extern RCGFWstate state;

/* error handler callbacks */
void _rcgfw_glfwInitFailure(RCGFWdisplay *display);
void _rcgfw_windowCreationFailure(RCGFWdisplay *display);
void _rcgfw_gladInitFailure(RCGFWdisplay *display);

/* actual implementation */
void rcgfwDefaultDisplayProperties(RCGFWdisplayProps *props)
{
    props->title = "RCGFW Window";
    props->width = 800;
    props->height = 600;
}

RCGFWdisplay *rcgfwCreateDisplay(RCGFWdisplayProps props)
{
    RCGFWdisplay *disp = malloc(sizeof(RCGFWdisplay)); // remember to free!!!
    if(disp == NULL) // small brain computer
        return NULL;

    disp->title = calloc(strlen(props.title) + 1, sizeof(char));
    if(disp->title == NULL) // once again, small brain computer
        return NULL;

    strcpy(disp->title, props.title);
    
    disp->width = props.width;
    disp->height = props.height;

    // couldn't initialize GLFW
    _rcgfw_checkDisplayError(!glfwInit(), "[RCGFW] FATAL ERROR -> \"Could not initalize GLFW!!\"", disp, &_rcgfw_glfwInitFailure);
    _RCGFW_WINDOW_HINTS; // define the window hints for the window to create.

    (disp->handle) = glfwCreateWindow(disp->width, disp->height, disp->title, NULL, NULL);
    const char *description;
    glfwGetError(&description);
    if(description != NULL) // If GLFW cannot create a window, display an error as to why.
        printf("%s\n", description);
    
    // cannot create the GLFW display
    _rcgfw_checkDisplayError(disp->handle == NULL, "[RCGFW] FATAL ERROR -> \"Could not create a GLFW window!\"", disp, &_rcgfw_windowCreationFailure);

    glfwMakeContextCurrent(disp->handle); // begin creation of opengl context
    _rcgfw_checkDisplayError(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress), "[RCGFW] FATAL ERROR -> \"Could not init GLAD\"", disp, &_rcgfw_gladInitFailure);

    return disp;
}

void rcgfwDestroyDisplay(RCGFWdisplay *display)
{
    free(display->title);
    glfwDestroyWindow(display->handle);
    display->handle = NULL;
    display->title = NULL;
    free(display);
    display = NULL;
    glfwTerminate();
}

RCGFWbool rcgfwDisplayShouldClose(void)
{
    return glfwWindowShouldClose(_rcgfw_getDisplay(&state)->handle);
}

void rcgfwDisplaySwap(void)
{
    glfwSwapBuffers(_rcgfw_getDisplay(&state)->handle);
    glfwPollEvents();
}

void rcgfwDisplayClear(RCGFWcolor color)
{
    glClearColor(color[0], color[1], color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

/*
 Running rcgfwClose is redundant as it's too early in the program
 to create anything that requires memory other than the display itself.
*/
void _rcgfw_glfwInitFailure(RCGFWdisplay *display)
{
    free(display->title);
    free(display);
    exit(-1);
}

void _rcgfw_windowCreationFailure(RCGFWdisplay *display)
{
    free(display->title);
    free(display);
    glfwTerminate();
    exit(-1);
}

void _rcgfw_gladInitFailure(RCGFWdisplay *display)
{
    glfwDestroyWindow(display->handle);
    free(display->title);
    free(display);
    glfwTerminate();
    exit(-1);
}