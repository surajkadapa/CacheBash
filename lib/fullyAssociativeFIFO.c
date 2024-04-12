#include "fullyAssociative.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//need a circular queue to implement FIFO 
int *items; //queue, need to alocate size when making cache table
int size = 0; //imp for circular operation
int front, rear = -1;
void enQueue(int index){
    if(front == -1)
        front = 0
    rear = (rear + 1) % size;
    items[rear] = value;
}
void deQueue(){
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front = (front + 1) % size;
    }
}

typedef struct cacheMemoryBlock{
    int index;
    char *tag;
    unsigned int data;

}