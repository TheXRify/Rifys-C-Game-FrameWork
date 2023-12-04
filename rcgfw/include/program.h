#ifndef RCGFW_PROGRAM_H
#define RCGFW_PROGRAM_H

#include "defs.h"
#include "types.h"

RCGFWshaderProgram rcgfwCreateProgram(void);
void rcgfwDestroyProgram(void);
void rcgfwLinkProgram(void);
void rcgfwUseProgram(void);

#endif