#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_1.h"

struct HuffNode* createHuffNode(char ch, int w) {
    struct HuffNode* node = (struct HuffNode*)calloc(1, sizeof(struct HuffNode));
    node->ch = ch;
    node->w = w;
    node->next = NULL;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}
static HuffNode* insert_node(struct HuffNode* ht, struct HuffNode* s) {
    if (ht == NULL) {
        return s;
    }
    if (s->w > ht->w) {
        s->next = ht;
        return s;
    }
    struct HuffNode* tempHfnode = ht;
    struct HuffNode* preHfnode = tempHfnode;
    while (tempHfnode != NULL) {
        if (s->w < tempHfnode->w) {
            preHfnode = tempHfnode;
            tempHfnode = tempHfnode->next;
            continue;
        }
        preHfnode->next = s;
        s->next = tempHfnode;
        break;
    }
    if (tempHfnode == NULL) {
        preHfnode->next = s;
    }
    return ht;
}
struct HuffNode* removeLastHuffNode(struct HuffNode* ht) {
    struct HuffNode* tempHfnode = ht;
    struct HuffNode* preHfnode = tempHfnode;
    while (tempHfnode->next != NULL) {
        preHfnode = tempHfnode;
        tempHfnode = tempHfnode->next;
    }
    preHfnode->next = NULL;
    return tempHfnode;
}
struct HuffNode* createTree(struct HuffNode* head) {
    if (head == NULL) {
        return NULL;
    }
    while (1) {
        struct HuffNode* node1 = removeLastHuffNode(head);
        if (node1 == head) {
            return node1;
        }
        struct HuffNode* node2 = removeLastHuffNode(head);
        if (node2 == head) {
            head = NULL;
        }
        struct HuffNode* newNode = createHuffNode(0, node1->w + node2->w);
        newNode->lchild = node1->w <= node2->w ? node1 : node2;
        newNode->rchild = node1->w <= node2->w ? node2 : node1;
        head = insert_node(head, newNode);
    }
}