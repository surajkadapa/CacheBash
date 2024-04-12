#ifndef fullyAssociativeFIFO_h
#define fullyAssociativeFIFO_h

void loadInstfmFIFO(double instLength, double tag, double index, double offset);
void makeCacheTable(int instLength, double tag, double index, double offset);
int updateCache(char *instruction, double tag, double index, double offset);

#endif