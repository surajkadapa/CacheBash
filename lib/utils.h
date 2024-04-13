#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>

void clearInputBuffer();

void slice(const char* str, char *result, size_t start, size_t end);

int convert(char *binary);




#endif
