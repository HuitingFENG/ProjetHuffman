#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arbre_1.h"

// Question D
struct HuffNode* newnewNode(char cc, int ww) {
    struct HuffNode* temp=(struct HuffNode*)malloc(sizeof(struct HuffNode));
    temp->ch = cc;
    temp->w = ww;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->next = NULL;
    return temp;
}
void minimize(struct MinNode* minNode, int pos) {
    int minimum = pos;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;
    if ((lchild < minNode->size) && (minNode->tab[lchild]->w < minNode->tab[minimum]->w))
        minimum = lchild;
    if ((rchild < minNode->size) && (minNode->tab[rchild]->w < minNode->tab[minimum]->w))
        minimum = rchild;
    if (minimum != pos) {
        struct HuffNode* temp=minNode->tab[minimum];
        minNode->tab[minimum]=minNode->tab[pos];
        minNode->tab[pos]=temp;
        minimize(minNode, minimum);
    }
}
struct HuffNode* get_minNode(struct MinNode* minNode) {
    struct HuffNode* temp = minNode->tab[0];
    minNode->tab[0] = minNode->tab[minNode->size - 1];
    minNode->size--;
    minimize(minNode, 0);
    return temp;
}
void insert_minNode(struct MinNode* minNode, struct HuffNode* parent) {
    minNode->size++;
    int i = minNode->size - 1;
    // la methode dichotomique pour chercher la position d'insertation du noeud parent
    // 3 positions importantes : debut, milieu, fin
    while (i && minNode->tab[(i - 1) / 2]->w > parent->w) {
        minNode->tab[i] = minNode->tab[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    // on met des noeuds parents de la droit a la gauche dans le tab
    // on cree l'arbre Huffman de la droit a la gauche du bas au haut
    minNode->tab[i] = parent;
}
struct MinNode* create_list_minNode(struct HuffNode* L) {
    char ch[MAX_CODE];
    int w[MAX_CODE];
    int size=0;
    while (L!=NULL){
        ch[size]=L->ch;
        w[size]=L->w;
        size++;
        L=L->next;
    }
    struct MinNode* minNode = (struct MinNode*)malloc(sizeof(struct MinNode));
    minNode->cap = size;
    minNode->tab = (struct HuffNode**)malloc(sizeof(struct HuffNode*)*minNode->size);
    for (int i = 0; i < size; i++)
        minNode->tab[i] = newnewNode(ch[i], w[i]);
    minNode->size = size;
    int j, n = minNode->size - 1;
    for (j = (n - 1) / 2; j >= 0; j--){
        minimize(minNode, j);
    }
    return minNode;
}
struct HuffNode* creer_HuffmanTree(struct HuffNode* L) {
    struct HuffNode *lchild, *rchild, *parent;
    struct MinNode* minNode = create_list_minNode(L);
    char ch[MAX_CODE];
    int w[MAX_CODE];
    int size=0;
    while (L!=NULL){
        ch[size]=L->ch;
        w[size]=L->w;
        size++;
        L=L->next;
    }
    while(minNode->size != 1){
        lchild = get_minNode(minNode);
        rchild = get_minNode(minNode);
        parent=newnewNode('#', lchild->w + rchild->w);
        parent->lchild = lchild;
        parent->rchild = rchild;
        insert_minNode(minNode, parent);
    }
    return get_minNode(minNode);
}
void display_tree(struct HuffNode* tree){
    if (tree==NULL){
        return;
    }
    printf("%c-%d\n", tree->ch, tree->w);
    display_tree(tree->lchild);
    display_tree(tree->rchild);
}
void free_hufftree(struct HuffNode* ht){
    if (ht != NULL){
        struct HuffNode* lchild=ht->lchild;
        struct HuffNode* rchild=ht->rchild;
        free(ht);
        free_hufftree(lchild);
        free_hufftree(rchild);
    }
}
