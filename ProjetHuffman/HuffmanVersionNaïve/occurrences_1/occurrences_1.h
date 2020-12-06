#ifndef occurrences_1_h
#define occurrences_1_h

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

void Input2Binary(char* sInput, char* sBinary);
int compter(char* sInput);

struct HuffNode* newNode(int ww, char cc);
int is_empty(struct HuffNode* root);
void push(struct HuffNode** root, int ww, char cc);
void display_pile(struct HuffNode* L);
struct HuffNode* sort_pile(struct HuffNode* root);
struct HuffNode* list_occurrences(char* sInput);
void free_list(struct HuffNode* L);



#endif /* occurrences_1_h */
