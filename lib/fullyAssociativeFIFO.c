#include "fullyAssociativeFIFO.h"
#include "hex_to_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void slice(const char *str, char *result, size_t start, size_t end){
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
void deQueue(){
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1) % size;
    }
}

int cacheHit, cacheMiss = 0;
int total = 0;

void loadInstFaFIFO(double instLength, double tag, double offset, double cacheBlocks){
    char data[100];
    float hitPercent;
    float missPercent;
    printf("\nEnter the data to load(in hex): ");
    clearInputBuffer();
    
}


typedef struct cacheMemoryBlock{
    int index; //should implement FIFO using this index itself
    char *tag;
    unsigned int data;
}cacheMemoryBlock;

cacheMemoryBlock *Blocks;
int noBlocks = 0;

void makeCacheTableFaFIFO(int instLngth, double tag, double offset, double cacheBlocks){
    printf("\nCache Memory Table(FA-FIFO)\n");
    printf("+-------------+-------------+-------------+\n");
    printf("|    Index    |     Tag     |     Data    |\n");
    printf("+-------------+-------------+-------------+\n");
    int noBlocks = 0;
    noBlocks = (int) cacheBlocks;
    size = noBlocks;
    items = malloc(size*sizeof(int));
    Blocks = malloc(noBlocks*sizeof(cacheMemoryBlock));
    for(int i = 0; i<noBlocks; i++){
        Blocks[i].index = i;
        printf("|      %d      |     Tag     |     Data    |\n",Blocks[i].index);
        printf("+-------------+-------------+-------------+\n");
    }

}