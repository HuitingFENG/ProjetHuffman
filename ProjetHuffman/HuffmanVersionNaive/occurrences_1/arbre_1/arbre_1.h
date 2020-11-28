

#ifndef ARBRE_1
#define ARBRE_1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct HuffNode* createHuffNode(char ch, int w);
static HuffNode* insert_node(struct HuffNode* ht, struct HuffNode* s);
struct HuffNode* removeLastHuffNode(struct HuffNode* ht);
struct HuffNode* createTree(struct HuffNode* head);

#endif //