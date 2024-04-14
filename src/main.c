#include "../lib/hex_to_bin.h"
#include "../lib/directMapped.h"
#include "../lib/fullyAssociativeFIFO.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//testing workflows
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


int main(){
    prntStart();
    double cacheSize, memSize, offset = 0;
    printf("Enter the cache size: ");
    scanf("%lf",&cacheSize);
    printf("Enter the memory size: ");
    scanf("%lf",&memSize);
    printf("Enter the number of offset bits: ");
    scanf("%lf",&offset);
    int type = 0;
    printf("Select an option\n");
    printf("\t1. Direct Mapped Cache(no replacement algorithim)\n");
    printf("\t2. Fully Associative Cache(FIFO replacment policy)\n");
    printf("Option: ");
    scanf("%d", &type);
    double instLength, index, tag, cacheBlocks = 0;
    switch(type){
        case 1:
            instLength = log2(memSize);
            index = log2((cacheSize/pow(2,offset)));
            tag = instLength-offset-index;
            instFormatPrint(instLength, tag, index, offset);
            int length = (int)instLength;
            makeCacheTable(length, tag, index, offset);
            loadInstdm(instLength, tag, index, offset);
            break;
        case 2:
            instLength = log2(memSize);
            tag = instLength-offset;
            double calc2 = pow(2, offset);
            cacheBlocks =  (cacheSize/calc2);
            printf("%lf",cacheBlocks);
            makeCacheTableFaFIFO(instLength, tag, offset, cacheBlocks);
            loadInstFaFIFO(instLength, tag, offset, cacheBlocks);
            break;
    }
    return 0;
}