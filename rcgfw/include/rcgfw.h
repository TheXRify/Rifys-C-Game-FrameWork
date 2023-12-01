#ifndef RCGFW_H
#define RCGFW_H

#include "defs.h"
#include "types.h"
#include "resource.h"

#include "display.h"
#include "shader.h"

void rcgfwInit(RCGFWdisplayProps props);
void rcgfwClose(void);

#endif