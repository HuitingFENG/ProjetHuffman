#pragma once

#ifndef OCCURRENCES_2
#define OCCURRENCES_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HuffNode {      // pour créer un arbre HuffTree
    int w;       // nombre d'occurences d'une caractère
    char ch;
    struct HuffNode* next;
    struct HuffNode* lchild;
    struct HuffNode* rchild;
}HuffNode, * HuffTree;
typedef struct HuffCode {    // pour créer un dictionnaire
    char ch;
    char* s;
    int len;
}HuffCode;

struct HuffNode* dichotomique_occurrences(char* sIn, char* sOut, char* dico);
struct HuffNode* AVL_occurrences(char* sIn, char* sOut, char* dico);

#endif // 