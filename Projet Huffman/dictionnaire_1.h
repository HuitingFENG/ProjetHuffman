#ifndef dictionnaire_1_h
#define dictionnaire_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

typedef struct HuffNode {
    // w est le nombre d'occurences d'une caractere (= weight)
    int w;
    // ch est le caractere (= character)
    char ch;
    // utiliser next pour faire une LSC et une pile
    struct HuffNode* next;
    // utiliser l'enfant gauche et l'enfant droit pour faire un arbre Huffman
    struct HuffNode* lchild;
    struct HuffNode* rchild;
}HuffNode, *HuffTree;

typedef struct MinNode {
    struct HuffNode** tab;
    int size;
    int cap;
}MinNode;

void printCodes(struct HuffNode* root, int arr[], int parent, FILE* fp);
void HuffmanCodes(struct HuffNode* L, FILE* fp);
void write_dictonnaire(struct HuffNode* L, char* dico);



#endif /* dictionnaire_1_h */
