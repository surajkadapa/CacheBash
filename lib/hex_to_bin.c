#include "hex_to_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *convertHexToBin(char *hexString, int instrLength) {
    char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    char digits[] = "0123456789abcdef";
    size_t hexStringLength = strlen(hexString);
    char *res = (char *)malloc(instrLength * sizeof(char));
    if (res == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    int temp = instrLength-1;
    memset(res, '0', temp);
    res[temp] = '\0'; 
    int p = hexStringLength - 1; 
    int index = temp;
    while (p >= 0) {
        const char *v = strchr(digits, tolower(hexString[p]));
        if (v != NULL) {
            int value;
            if (v[0] > 96) {
                value = v[0] - 87;
            } else {
                value = v[0] - 48;
            }
            strncpy(res + index - 3, binary[value], 4);
        } else {
            printf("Invalid character: %c\n", hexString[p]);
            free(res);
            return NULL;
        }
        p--;
        index -= 4;
    }
    return res;
}

