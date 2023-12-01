#include "shader.h"
#include "resource.h"

#include "rcgfw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

extern RCGFWstate state;

extern void _rcgfw_add_shader(RCGFWshader shader);
extern int _rcgfw_get_shader(void *offset);

extern void _rcgfw_checkError(RCGFWbool condition, const char *msg, void (*callback)());
extern void _rcgfw_critical_error();

void rcgfwCreateShader(const char *name, RCGFWshaderType shaderType)
{
    // grab the shader source code and get ready for shader creation
    char *path = calloc(strlen(RCGFW_SHADERS_PATH) + strlen(name) + strlen(".glsl") + 1, sizeof(char));
    strcpy(path, RCGFW_SHADERS_PATH);
    strcat(path, name);
    strcat(path, ".glsl");
    char *src = rcgfwLoadShader(path);
    _rcgfw_checkError(src == NULL, "[RCGFW] FATAL ERROR -> \"Could not get the shader source!\"", &_rcgfw_critical_error);

    // shader creation
    RCGFWshader shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("[RCGFW] FATAL ERROR -> \"Shader compilation error: (%s)\"\n", infoLog);
        rcgfwClose();
        exit(-1);
    }

    _rcgfw_add_shader(shader);

    free(src);
    free(path);
}

void rcgfwDestroyShader(void *offset)
{
    int shader = _rcgfw_get_shader(offset);
    glDeleteShader(shader);
}