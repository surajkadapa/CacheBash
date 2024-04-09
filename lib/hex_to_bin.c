#include "hex_to_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *convertHexToBin(char *hexString){
    char binary[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101","0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110","1111"};
    char digits [] = "0123456789abcdef";
    size_t hexStringLength = strlen(hexString);
    char *res = (char *)malloc((hexStringLength * 4 + 1) * sizeof(char));
    res[0] = '\0';
    int p = 0;
    int value =0;
        while(hexString[p]){
            const char *v = strchr(digits, tolower(hexString[p]));
            if(v[0]>96){
                value=v[0]-87;
            }
            else{
                value=v[0]-48;
            }
            if (v){
                strcat(res, binary[value]);
            }
            p++;
        }
    return res;
}