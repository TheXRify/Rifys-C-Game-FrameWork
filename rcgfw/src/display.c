#include "display.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <string.h>
#include <err.h>

struct rcgfw_display
{
    GLFWwindow *window;
    char *title;
    RCGFWuint width, height;
};

void _rcgfw_init_glfw(RCGFWdisplay *display);
void _rcgfw_init_glad(RCGFWdisplay *display);
void _rcgfw_framebuffer_size_callback(GLFWwindow *window, int width, int height);

RCGFWdisplay *rcgfwCreateDisplay(const char *title, RCGFWuint width, RCGFWuint height)
{
    RCGFWdisplay *display = malloc(sizeof(RCGFWdisplay));

    display->title = calloc(strlen(title) + 1, sizeof(char));
    strcpy(display->title, title);

    display->width = width;
    display->height = height;

    _rcgfw_init_glfw(display);
    _rcgfw_init_glad(display);

    glViewport(0, 0, display->width, display->height);
    glfwSetFramebufferSizeCallback(display->window, _rcgfw_framebuffer_size_callback);

    return display;
}

void rcgfwDestroyDisplay(RCGFWdisplay *display)
{
    free(display->title);
    glfwDestroyWindow(display->window);
    glfwTerminate();
    free(display);
}

void rcgfwDisplayClear(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void rcgfwDisplayShow(RCGFWstate *state)
{
    glfwSwapBuffers(state->display->window);
    glfwPollEvents();
}

/* ============================================ INTERNAL FUNCTIONS ============================== */
void _rcgfw_init_glfw(RCGFWdisplay *display)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    display->window = glfwCreateWindow(display->width, display->height, display->title, NULL, NULL);
    if(display->window == NULL)
    {
        glfwTerminate();
        free(display->title);
        free(display);
        errx(-1, "Failed to create an opengl display\n");
    }
    glfwMakeContextCurrent(display->window);
}

void _rcgfw_init_glad(RCGFWdisplay *display)
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        free(display->title);
        glfwDestroyWindow(display->window);
        glfwTerminate();
        free(display);
        errx(-1, "Failed to initialize glad.\n");
    }
}

void _rcgfw_framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}