#ifndef dictionnaire_1_h
#define dictionnaire_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000



void printCodes(struct HuffNode* root, int arr[], int parent, FILE* fp);
void HuffmanCodes(struct HuffNode* L, FILE* fp);
void write_dictonnaire(struct HuffNode* L, char* dico);



#endif /* dictionnaire_1_h */
