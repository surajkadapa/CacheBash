#ifndef fullyAssociativeFIFO_h
#define fullyAssociativeFIFO_h

void loadInstFaFIFO(double instLength, double tag, double offset, double cacheBlocks);
void makeCacheTableFaFIFO(int instLength, double tag, double index, double offset);
int updateCacheFaFIFO(char *instruction, double tag, double offset);

#endif