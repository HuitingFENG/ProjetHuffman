
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire_1.h"


// Question E
void printCodes(struct HuffNode* root, int arr[], int parent, FILE* fp) {
    if (root->lchild) {
        // chaque branche gauche de l'arbre Huffman est '0'
        arr[parent] = 0;
        printCodes(root->lchild, arr, parent + 1, fp);
    }
    // on arrive à trouver la feuille de l'arbre Huffman
    if (!(root->lchild) && !(root->rchild)) {
        printf("%c ", root->ch);
        fprintf(fp,"%c ", root->ch);
        for (int i=0;i< parent ;i++){
            printf("%d", arr[i]);
            fprintf(fp, "%d", arr[i]);
        }
        // important d'ajouter un retour à la ligne pour faciliter a encoder
        printf("\n");
        fprintf(fp,"\n");
    }
    if (root->rchild) {
        // chaque branche droite de l'arbre Huffman est '1'
        arr[parent] = 1;
        printCodes(root->rchild, arr, parent + 1,fp);
    }
}
void HuffmanCodes(struct HuffNode* L, FILE* fp) {
    struct HuffNode* root = creer_HuffmanTree(L);
    int arr[MAX_INPUT], parent = 0;
    // important de mettre fp dans les parametres de la fonction recursive printCodes
    printCodes(root, arr, parent,fp);
}
void write_dictonnaire(struct HuffNode* L, char* dico){
    FILE* fp=fopen(dico,"w+");
    HuffmanCodes(L, fp);
    printf("You can find it in the Alice_dico.txt.\n");
    fclose(fp);
}
