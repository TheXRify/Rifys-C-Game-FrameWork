#ifndef RCGFW_TYPE_H
#define RCGFW_TYPE_H

typedef unsigned char RCGFWbool;
typedef unsigned char RCGFWbyte;
typedef unsigned int RCGFWuint;
typedef unsigned short RCGFWword;

typedef struct rcgfw_display RCGFWdisplay;

typedef struct rcgfw_state {
    RCGFWdisplay *display;
    RCGFWbool running;
} RCGFWstate;

#endif