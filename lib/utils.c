#include "utils.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void slice(const char* str, char *result, size_t start, size_t end){
    strncpy(result, str+start, end-start);
}

int convert(char *binary){
    int result = 0;
    int length = strlen(binary);

    for(int i = 0; i < length; i++){
        int digit = binary[i] - '0';
        result = result * 2 + digit;
    }
    return result;
}

