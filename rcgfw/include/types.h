#ifndef RCGFW_TYPES_H
#define RCGFW_TYPES_H

typedef unsigned int RCGFWuint;
typedef unsigned long long RCGFWsize;
typedef unsigned char RCGFWbool;

typedef float RCGFWcolor[3];

typedef enum rcgfw_shader_type
{
    RCGFW_FRAGMENT_SHADER = 0x8B30,
    RCGFW_VERTEX_SHADER,
    RCGFW_GEOMETRY_SHADER = 0x8DD9,
    RCGFW_COMPUTE_SHADER = 0x91B9
} RCGFWshaderType;

typedef unsigned int RCGFWu32;
typedef RCGFWu32 RCGFWshader;
typedef RCGFWu32 RCGFWshaderProgram;

typedef struct rcgfw_display_props
{
    unsigned int width, height;
    char *title;
} RCGFWdisplayProps;

typedef struct rcgfw_display RCGFWdisplay;
typedef struct rcgfw_state RCGFWstate;

#endif