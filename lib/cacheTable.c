#include "cacheTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

typedef struct cacheMemoryBlock{ //in progress - still need to add valid and dirty bits
    int index;
    char *tag;
    char *data; //requires some work to link to the real memory location, will take some tinkering
}cacheMemoryBlock;

cacheMemoryBlock *Blocks;
int NoBlcks = 0;
void makeCacheTable(int instLength, double tag, double index, double offset){
    printf("\nCache Memory Table\n");
    printf("+-------------+-------------+-------------+\n");
    printf("|    Index    |     Tag     |     Data    |\n");
    printf("+-------------+-------------+-------------+\n");
    double noBks = pow(2, index);
    NoBlcks = (int)noBks;
    Blocks = malloc(NoBlcks*sizeof(cacheMemoryBlock));
    for(int i = 0; i<NoBlcks; i++){
        Blocks[i].index = i;
        printf("|      %d      |     Tag     |     Data    |\n",Blocks[i].index);
        printf("+-------------+-------------+-------------+\n");
    }
}

void updateCache(char *instruction, double tag, double index, double offset){
    int tagI = (int)tag;
    char *tagBlock = malloc((tagI + 1)*sizeof(char));
    tagBlock[tagI] = '\0';
    int indexI = (int)index;
    char *indexBlock = malloc((indexI + 1)*sizeof(char));
    indexBlock[indexI] = '\0';
    int offsetI = (int)offset;
    char *offsetBlock = malloc((offset + 1)*sizeof(char));
    offsetBlock[offsetI] = '\0';
    slice(instruction, tagBlock, 0, 0+tagI);
    slice(instruction, indexBlock, (0+tagI), (0+tagI)+indexI);
    slice(instruction, offsetBlock, ((0+tagI)+indexI), ((0+tagI)+indexI)+offsetI);
    /** printf("\n%s\n",tagBlock);
    printf("\n%s\n",indexBlock);
    printf("\n%s\n",offsetBlock); **/ //debugging
    int inIndex = convert(indexBlock);
    Blocks[inIndex].index = inIndex;
    Blocks[inIndex].tag = malloc(strlen(tagBlock)*sizeof(char));
    strcpy(Blocks[inIndex].tag, tagBlock);
    printf("\nCache Memory Table\n");
    printf("+-------------+-----------------+-------------+\n");
    printf("|    Index    |       Tag       |     Data    |\n");
    printf("+-------------+-----------------+-------------+\n");
    for(int i = 0; i<NoBlcks; i++){
        printf("|      %d      |     %s     |     %s    |\n",Blocks[i].index, Blocks[i].tag, Blocks[i].data);
        printf("+-------------+----------------+-------------+\n");
    }
}