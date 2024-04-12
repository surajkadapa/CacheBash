#ifndef direcctMapped_h
#define direcctMapped_h

void loadInstdm(double instLength, double tag, double index, double offset);
void makeCacheTable(int instLength, double tag, double index, double offset);
int updateCache(char *instruction, double tag, double index, double offset); //will need work when implementing store

#endif