#include "fullyAssociativeFIFO.h"
#include "hex_to_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"


//need a circular queue to implement FIFO 
int *items; //queue, need to alocate size when making cache table
int size = 0; //imp for circular operation
int front, rear = -1;
void enQueue(int index){
    if(front == -1)
        front = 0;
    rear = (rear + 1) % size;
    items[rear] = index;
}
int deQueue(){
    int result = items[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1) % size;
    }
    return result;
}

extern int cacheHit, cacheMiss;
extern int total;

void loadInstFaFIFO(double instLength, double tag, double offset, double cacheBlocks){
    char data[100];
    float hitPercent;
    float missPercent;
    printf("\nEnter the data to load(in hex): ");
    clearInputBuffer();
    fgets(data, sizeof(data), stdin);
    if(data[strlen(data)-1] == '\n'){
        data[strlen(data)-1] = '\0';
    }
    int length = (int)instLength;
    char *res = convertHexToBin(data, length);
    int ret = updateCacheFaFIFO(res, tag, offset);
    if(ret == 1){
        total++;
        cacheHit++;
    }else{
        total++;
        cacheMiss++;
    }
    hitPercent = ((float)cacheHit/total)*100;
    missPercent = ((float)cacheMiss/total)*100;
    printf("\nCache Hits: %.2f%%", hitPercent);
    printf("\nCache Misses: %.2f%%", missPercent);
    while(1==1){
        char data[100];
        float hitPercent;
        float missPercent;
        printf("\nEnter the data to load(in hex): ");
        fgets(data, sizeof(data), stdin);
        if(data[strlen(data)-1] == '\n'){
            data[strlen(data)-1] = '\0';
        }
        int length = (int)instLength;
        char *res = convertHexToBin(data, length);
        int ret = updateCacheFaFIFO(res, tag, offset);
        if(ret == 1){
            total++;
            cacheHit++;
        }else{
            total++;
            cacheMiss++;
        }
        hitPercent = ((float)cacheHit/total)*100;
        missPercent = ((float)cacheMiss/total)*100;
        printf("\nCache Hits: %.2f%%", hitPercent);
        printf("\nCache Misses: %.2f%%", missPercent);
    }
}


typedef struct cacheMemoryBlock{
    int index; //should implement FIFO using this index itself
    char *tag;
    unsigned int data;
}cacheMemoryBlock;

extern cacheMemoryBlock *Blocks;
int noBlocks = 0;
void makeCacheTableFaFIFO(int instLngth, double tag, double offset, double cacheBlocks){
    printf("\nCache Memory Table(FA-FIFO)\n");
    printf("+-------------+-------------+-------------+\n");
    printf("|    Index    |     Tag     |     Data    |\n");
    printf("+-------------+-------------+-------------+\n");
    noBlocks = (int) cacheBlocks;
    size = noBlocks;
    items = malloc(size*sizeof(int));
    Blocks = malloc(noBlocks*sizeof(cacheMemoryBlock));
    for(int i = 0; i<noBlocks; i++){
        Blocks[i].index = i;
        Blocks[i].tag = malloc((tag + 1) * sizeof(char));
        strcpy(Blocks[i].tag, "NULL");
        printf("|      %d      |     Tag     |     Data    |\n",Blocks[i].index);
        printf("+-------------+-------------+-------------+\n");
    }
    for(int i=0; i<noBlocks; i++){
        enQueue(i);
    }
}

int updateCacheFaFIFO(char *instruction, double tag, double offset){
    int retValue = -1;
    int tagI = (int)tag;
    char *tagBlock = malloc((tagI + 1)*sizeof(char));
    tagBlock[tagI] = '\0';
    int offsetI = (int)offset;
    char *offsetBlock = malloc((offsetI + 1)*sizeof(char));
    offsetBlock[offsetI] = '\0';
    slice(instruction, tagBlock, 0, 0+tagI);
    slice(instruction, offsetBlock, (0+tagI), (0+tagI)+offsetI);
    int found = 0;
    for(int i = 0; i<noBlocks; i++){
        printf("%s\n",Blocks[i].tag);
        if(strcmp(Blocks[i].tag, tagBlock)==0){
            found = 1;
            retValue = 1;
            return retValue;
            break;
        }
    }
    if(found == 0){ //data has not been found in the cache table
        int addIndex = deQueue();
        enQueue(addIndex);
        strcpy(Blocks[addIndex].tag, tagBlock);
        printf("not found");
        return retValue;
    }
}

