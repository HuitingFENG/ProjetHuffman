#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "occurrences.h"

int compter(char* sIn) {
    char ch;
    int count = 0;
    FILE* fptr;
    fptr = fopen(sIn, "r");
    while ((ch = fgetc(fptr)) != EOF) {
        count++;
    }
    fclose(fptr);
    return count;
}

struct HuffNode* newNode(int ww, char cc)
{
    struct HuffNode* stackNode = (struct HuffNode*)malloc(sizeof(struct HuffNode));
    stackNode->w = ww;
    stackNode->ch = cc;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct HuffNode* root)
{
    return !root;
}

void push(struct HuffNode** root, int data, char cc)
{
    struct HuffNode* stackNode = newNode(data, cc);
    stackNode->next = *root;
    *root = stackNode;
    //printf("%c %d pushed to stack\n", cc,data);
}

struct HuffNode pop(struct HuffNode** root)
{
    if (isEmpty(*root))
        printf("error!");
    struct HuffNode* temp = *root;
    *root = (*root)->next;
    struct HuffNode popped_node = (*temp);
    free(temp);
    return popped_node;
}

void peek(struct HuffNode* root)
{
    if (isEmpty(root))
        printf("error !");
    printf("%c : %d ", root->ch, root->w);
}

void display_pile(struct HuffNode* L) {
    if (L == NULL) {
        return;
    }
    printf("Notre liste d'occurrences est : \n");
    while (L != NULL) {
        printf("%c : %d\n", L->ch, L->w);
        L = L->next;
    }
}

struct HuffNode* sort_stack(struct HuffNode* root) {
    struct HuffNode* head1, * p, * q, * pmax, * qmax;
    head1 = NULL;
    while (root) {
        for (q = pmax = root, p = root->next;p;q = p, p = p->next) {
            if (p->w > pmax->w) {
                pmax = p;
                qmax = q;
            }
        }
        if (pmax != root) {
            qmax->next = pmax->next;
        }
        else {
            root = root->next;
        }
        pmax->next = head1;
        head1 = pmax;
    }
    return head1;
}
struct HuffNode* list_occurrences(char* sIn) {
    int list_frequency[256] = { 0 };
    int i, j;
    struct HuffNode* root = NULL;
    FILE* fp = fopen(sIn, "r");
    if (fp == NULL) {
        printf("open error ! \n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int fileSize;
    fileSize = ftell(fp);
    //printf("%d\n",fileSize);
    char* strText;
    fseek(fp, 0, SEEK_SET);
    strText = (char*)malloc(fileSize * sizeof(char));
    fread(strText, fileSize, sizeof(char), fp);
    strText[fileSize] = '\0';
    //printf("%s\n", strText);
    for (int i = 0; strText[i] != '\0';i++) {
        list_frequency[strText[i]]++;
    }
    for (int i = 0;i < 256;i++) {
        if (list_frequency[i] != 0) {
            push(&root, list_frequency[i], i);
            //printf("%c : %d \n", i,list_frequency[i]);
        }
    }
    display_pile(sort_stack(root));
    fclose(fp);
    return sort_stack(root);
}