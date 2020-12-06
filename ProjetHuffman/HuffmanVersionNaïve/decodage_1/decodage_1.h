#include <stdio.h>
#include "decodage_1.h"
#include "arbre_1.h"
#include "dictionnaire_1.h"

// Question H
void decompresser_petitTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage){
    FILE* fp1=fopen(sHuffmanFinal,"r");
    FILE* fp2=fopen(sDecodage,"w+");
    char* str_decodage;
    // strText est les caracteres stockes dans le fichier encodage
    char* strText;
    if(fp1==NULL || fp2==NULL){
        printf ("open error ! \n");
        exit(1);
    }
    int fileSize;
    fileSize=ftell(fp1);
    fseek(fp1,0L,SEEK_END);
    fileSize=ftell(fp1);
    printf("\nles bits du fichier d'encodage Alice_huffman_final : %d\n", fileSize);
    fseek(fp1, 0, SEEK_SET);
    strText=(char*)malloc(fileSize*sizeof(char));
    fread(strText, fileSize, sizeof(char), fp1);
    strText[fileSize]='\0';
    // definir un pointeur temporaire pour parcourir l'arbre Huffman
    struct HuffNode* temp=ht;
    int j=0, i=0;
    for (i=0; i<strlen(strText); i++){
        // dans l'arbre Huffman, chaque branche gauche est '0', chaque branche droite est '1'
        if(strText[i]=='0')
            temp=temp->lchild;
        else
            temp=temp->rchild;
        // dans l'arbre Huffman, chaque feuille stocke un caractere du texte qu'on veut
        // on trouve maintenant la feuille et on la stocke dans str_decodage[]
        if(temp->lchild==NULL && temp->rchild==NULL){
            str_decodage[j]=temp->ch;
            temp=ht;
            j++;
        }
    }
    printf("After decodage : %s", str_decodage);
    printf("\nFinish decoding ! You can find it in the Alice_decodage.txt.\n");
    // fputs() permet de mettre directement un string dans le fichier
    fputs(str_decodage, fp2);
    fclose(fp1);
    fclose(fp2);
}
void decompresser_grandTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage){
    FILE* fp1=fopen(sHuffmanFinal,"r");
    FILE* fp2=fopen(sDecodage,"w+");
    char* str_decodage;
    // strText est les caracteres stockes dans le fichier encodage
    char* strText;
    if(fp1==NULL || fp2==NULL){
        printf ("open error ! \n");
        exit(1);
    }
    int fileSize, tempFileSize;
    tempFileSize=ftell(fp1);
    fseek(fp1,0L,SEEK_END);
    fileSize=ftell(fp1);
    fseek(fp1, fileSize, SEEK_SET);
    strText=(char*)malloc(fileSize*sizeof(char));
    fread(strText, sizeof(strText), sizeof(char), fp1);
    strText[fileSize]='\0';
    // definir un pointeur temporaire pour parcourir l'arbre Huffman
    struct HuffNode* temp=ht;
    int j=0, i=0;
    printf("\nles bits du fichier d'encodage Alice_huffman_final : %d\n", fileSize);
    for (i=0; i<strlen(strText); i++){
        // dans l'arbre Huffman, chaque branche gauche est '0', chaque branche droite est '1'
        if(strText[i]=='0')
            temp=temp->lchild;
        else
            temp=temp->rchild;
        // dans l'arbre Huffman, chaque feuille stocke un caractere du texte qu'on veut
        // on trouve maintenant la feuille et on la stocke dans str_decodage[]
        if(temp->lchild==NULL && temp->rchild==NULL){
            str_decodage[j]=temp->ch;
            temp=ht;
            j++;
        }
    }
    // printf("After decodage : %s", str_decodage);
    printf("Finish decoding ! You can find it in the Alice_decodage.txt.\n");
    // fputs() permet de mettre directement un string dans le fichier
    fputs(str_decodage, fp2);
    fclose(fp1);
    fclose(fp2);
}

