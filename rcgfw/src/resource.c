#include "rcgfw.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *_rcgfw_open_file_read(const char *path, size_t *size);
extern void _rcgfw_read_file_source(FILE *file, size_t size, char *source);
extern void _rcgfw_close_file(FILE *file);
extern void _rcgfw_checkError(RCGFWbool condition, const char *msg, void (*callback)());
extern void _rcgfw_critical_error();

void rcgfwResourceTest(void)
{
    size_t size;
    FILE *file = _rcgfw_open_file_read(RCGFW_SHADERS_PATH"vertex.glsl", &size);
    char *source = calloc(size, sizeof(char));
    _rcgfw_checkError(source == NULL, "[RCGFW] FATAL ERROR -> \"Could not allocate enough memory for an operation!\"", &_rcgfw_critical_error);
    _rcgfw_read_file_source(file, size, source);

    printf("%s\n", source);

    _rcgfw_close_file(file);
}