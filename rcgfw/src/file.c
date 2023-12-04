#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rcgfw.h"

extern void _rcgfw_checkError(RCGFWbool condition, const char *msg, void (*callback)());
extern void _rcgfw_critical_error();

FILE *_rcgfw_open_file_read(const char *path, size_t *size)
{
    FILE *file = fopen(path, "r");
    _rcgfw_checkError(file == NULL, "[RCGFW] FATAL ERROR -> \"Could not open file specified!\"", &_rcgfw_critical_error);

    fseek(file, 0l, SEEK_END);
    *size = ftell(file);
    rewind(file);

    return file;
}

FILE *_rcgfw_open_file_write(const char *path, size_t *size)
{
    FILE *file = fopen(path, "r");

    fseek(file, 0l, SEEK_END);
    *size = ftell(file);
    rewind(file);

    return file;
}

void _rcgfw_read_file_source(FILE *file, size_t size, char *source)
{
    fread(source, 1, size, file);
}

void _rcgfw_close_file(FILE *file)
{
    fclose(file);
}

char *_rcgfw_get_full_path(const char *name, const char *prefix)
{
    char *path = (char *) calloc(strlen(prefix) + strlen(name) + strlen(".glsl") + 1, sizeof(char));
    _rcgfw_checkError(path == NULL, "[RCGFW] FATAL ERROR -> \"Could not allocate enough memory for path.\"", &_rcgfw_critical_error);
    strcpy(path, prefix);
    strcat(path, name);
    strcat(path, ".glsl");
    return path;
}