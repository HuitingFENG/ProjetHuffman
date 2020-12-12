#ifndef decodage_1_h
#define decodage_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

void decompresser_petitTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage);
void decompresser_grandTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage);


#endif /* decodage_1_h */
