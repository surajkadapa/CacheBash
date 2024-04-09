#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/hex_to_bin.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct cacheMemoryBlock{ //in progress - still need to add valid and dirty bits
    int index;
    unsigned int tag;
    unsigned int data; //requires some work to link to the real memory location, will take some tinkering
}cacheMemoryBlock;


void prntStart(){
    system("clear");  
    printf("  _____            __        ___              __ \n");
    printf(" / ___/___ _ ____ / /  ___  / _ ) ___ _ ___  / / \n");
    printf("/ /__ / _ `// __// _ \\/ -_)/ _  |/ _ `/(_-< / _ \\ \n");
    printf("\\___/ \\_,_/ \\__//_//_/\\__//____/ \\_,_//___//_//_/ \n");
}

void instFormatPrint(double instLength, double tag, double index, double offset){
    printf("\n");
    printf("Instruction Format\n");
    printf("+---------+---------+---------+\n");
    printf("|   Tag   |  Index  |  Offset |\n");
    printf("+---------+---------+---------+\n");
    printf("|  %.0lf bits |  %.0lf bits |  %.0lf bits |\n",tag, index, offset);
    printf("+---------+---------+---------+\n");
}

void loadInst(double instLength){
    char data[100];
    printf("\nEnter the load data(in hex): ");
    clearInputBuffer(); 
    fgets(data, sizeof(data), stdin);
    if(data[strlen(data)-1] == '\n'){
        data[strlen(data)-1] = '\0';
    }
    int length = (int)instLength;
    char *res = convertHexToBin(data, length);
    printf("\n%s",res);
}

int main(){
    prntStart();
    double cacheSize, memSize, offset = 0;
    printf("Enter the cache size: ");
    scanf("%lf",&cacheSize);
    printf("Enter the memory size: ");
    scanf("%lf",&memSize);
    printf("Enter the number of offset bits: ");
    scanf("%lf",&offset);
    double instLength, index, tag, cacheBlocks = 0;
    instLength = log2(memSize);
    index = log2((cacheSize/pow(2,offset)));
    tag = instLength-offset-index;
    cacheBlocks = log2(cacheSize);
    instFormatPrint(instLength, tag, index, offset);
    loadInst(instLength);
    return 0;
}