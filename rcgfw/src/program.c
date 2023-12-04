#include "program.h"

#include "rcgfw.h"

#include <glad/glad.h>

#include <stdio.h>
#include <stdlib.h>

extern RCGFWshader _rcgfw_get_shader(void *offset);
extern RCGFWshaderProgram _rcgfw_get_shader_program(void);
extern RCGFWshader *_rcgfw_get_shader_ptr(void *offset);
extern int _rcgfw_get_num_shaders();

static void _rcgfw_check_program_linking(int program);

RCGFWshaderProgram rcgfwCreateProgram(void)
{
    static RCGFWshaderProgram program;
    program = glCreateProgram();
    return program;
}

void rcgfwDestroyProgram(void)
{
    int program = _rcgfw_get_shader_program();
    int shader = 0;
    for(int i = 0; i < _rcgfw_get_num_shaders(); i++)
    {
        shader = _rcgfw_get_shader((void*)i);
        glDetachShader(program, shader);
        glDeleteShader(shader);
    }
    glDeleteProgram(_rcgfw_get_shader_program());
}

void rcgfwLinkProgram(void)
{
    int program = _rcgfw_get_shader_program();
    glLinkProgram(program);
    _rcgfw_check_program_linking(program);
}

void rcgfwUseProgram(void)
{
    glUseProgram(_rcgfw_get_shader_program());
}

/* INTERNAL RCGFW FUNCTION DEFS */

void _rcgfw_attach_shader(void *shdrOffset, int program)
{
    RCGFWshader shader = _rcgfw_get_shader(shdrOffset);
    glAttachShader(program, shader);
}

/* STATIC FUNCTION DEFS */

void _rcgfw_check_program_linking(int program)
{
    int success;
    char infoLog[RCGFW_INFOLOG_MAX];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program,RCGFW_INFOLOG_MAX, NULL, infoLog);
        printf("[RCGFW] FATAL ERROR -> \"Program linking error: %s\"\n", infoLog);
        rcgfwClose();
        exit(-1);
    }
}