#ifndef encodage_1_h
#define encodage_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

void Input2Binary_dico(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal);
void compresser(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal);

#endif /* encodage_1_h */
