#ifndef RCGFW_TYPES_H
#define RCGFW_TYPES_H

typedef unsigned int RCGFWuint;
typedef unsigned long long RCGFWsize;
typedef unsigned char RCGFWbool;

typedef float RCGFWcolor[3];

typedef struct rcgfw_display_props
{
    unsigned int width, height;
    char *title;
} RCGFWdisplayProps;

typedef struct rcgfw_display RCGFWdisplay;
typedef struct rcgfw_state RCGFWstate;

#endif