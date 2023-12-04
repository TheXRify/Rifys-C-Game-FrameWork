#include "rcgfw.h"
#include "shader.h"
#include "resource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

extern RCGFWstate state;

extern void _rcgfw_add_shader(RCGFWshader shader);
extern int _rcgfw_get_shader(void *offset);
extern char *_rcgfw_get_full_path(const char *name, const char* prefix);

extern void _rcgfw_checkError(RCGFWbool condition, const char *msg, void (*callback)());
extern void _rcgfw_critical_error();

static void _rcgfw_check_shader_compilation(RCGFWshader shader);

void rcgfwCreateShader(const char *name, RCGFWshaderType shaderType)
{
    // grab the shader source code and get ready for shader creation
    char *path = _rcgfw_get_full_path(name, RCGFW_SHADERS_PATH);
    char *src = rcgfwLoadShader(path);
    free(path);
    _rcgfw_checkError(src == NULL, "[RCGFW] FATAL ERROR -> \"Could not get the shader source!\"", &_rcgfw_critical_error);

    // shader creation
    RCGFWshader shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    _rcgfw_check_shader_compilation(shader);

    _rcgfw_add_shader(shader);

    free(src);
}

void rcgfwDestroyShader(void *offset)
{
    int shader = _rcgfw_get_shader(offset);
    glDeleteShader(shader);
}

/* INTERNAL RCGFW FUNCTION DEFS */

/* STATIC FUNCTION DEFS */

void _rcgfw_check_shader_compilation(RCGFWshader shader)
{
    int success;
    char infoLog[RCGFW_INFOLOG_MAX];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, RCGFW_INFOLOG_MAX, NULL, infoLog);
        printf("[RCGFW] FATAL ERROR -> \"Shader compilation error: %s\"\n", infoLog);
        rcgfwClose();
        exit(-1);
    }
}