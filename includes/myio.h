#include <stdio.h>
#include <stdarg.h>

#ifndef MYIO_H
#define MYIO_H

int printfn(const char* format, ...)
{
    int result = 0;

    va_list ptr;
    va_start(ptr, format);
    result = vprintf(format, ptr);
    va_end(ptr);
    result += printf("\n");

    return result;
}

#endif
