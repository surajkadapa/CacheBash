#ifndef cacheTable_h
#define cacheTable_h

void makeCacheTable(int instLength, double tag, double index, double offset);
int updateCache(char *instruction, double tag, double index, double offset); //will need work when implementing store

#endif