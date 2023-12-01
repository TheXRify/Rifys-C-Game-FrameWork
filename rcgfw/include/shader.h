#ifndef RCGFW_SHADER_H
#define RCGFW_SHADER_H

#include "defs.h"
#include "types.h"

void rcgfwCreateShader(const char *name, RCGFWshaderType shaderType);
void rcgfwDestroyShader(void *offset);

#endif