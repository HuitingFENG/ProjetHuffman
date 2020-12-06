

#ifndef arbre_1_h
#define arbre_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000


typedef struct MinNode {
    struct HuffNode** tab;
    int size;
    int cap;
}MinNode;

struct HuffNode* newnewNode(char cc, int ww);
void minimize(struct MinNode* minNode, int pos);
struct HuffNode* get_minNode(struct MinNode* minNode);
void insert_minNode(struct MinNode* minNode, struct HuffNode* parent);
struct MinNode* create_list_minNode(struct HuffNode* L);
struct HuffNode* creer_HuffmanTree(struct HuffNode* L);
void display_tree(struct HuffNode* tree);
void free_hufftree(struct HuffNode* ht);


#endif /* arbre_1_h */
