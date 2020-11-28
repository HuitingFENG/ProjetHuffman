#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef OCCURRENCES
#define OCCURRENCES

typedef struct HuffNode {      // pour cr�er un arbre HuffTree
    int w;       // nombre d'occurences d'une caract�re
    char ch;
    struct HuffNode* next;
    struct HuffNode* lchild;
    struct HuffNode* rchild;
}HuffNode, * HuffTree;
typedef struct HuffCode {    // pour cr�er un dictionnaire
    char ch;
    char* s;
    int len;
}HuffCode;

int compter(char* sIn)`;
struct HuffNode* newNode(int ww, char cc);
int isEmpty(struct HuffNode* root);
void push(struct HuffNode** root, int data, char cc);
struct HuffNode pop(struct HuffNode** root);
void peek(struct HuffNode* root);
void display_pile(struct HuffNode* L);
struct HuffNode* sort_stack(struct HuffNode* root);
struct HuffNode* list_occurrences(char* sIn)

#endif // 