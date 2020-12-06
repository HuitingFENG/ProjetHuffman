#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "encodage_1.h"

// Question F
void Input2Binary_dico(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal){
    FILE* fp1=fopen(sInput,"r");
    // fichier sHuffman est un dictionnaire intermédaire, il faut supprimer '\n' pour obtenir le dictionnaire final
    FILE *fp2=fopen(sHuffman,"w+");
    FILE *fp3=fopen(dico,"r");
    FILE* fp4=fopen(sHuffmanFinal,"w+");
    int i=0,j=0,m=0,len_char;
    char c1;
    char str_input[MAX_INPUT];
    char str_char[MAX_CODE];
    char str_code[MAX_CODE];
    if(fp1==NULL || fp2==NULL || fp3==NULL){
        printf("open error !\n");
        exit(1);
    }
    printf("\nStart to encode an example with the dictionnary... \n");
    // fgetc() pour chaque caractere, fgets() pour chaque ligne
    c1=fgetc(fp1);
    while (c1!=EOF){
        printf("%c",c1);
        str_input[i]=c1;
        c1=fgetc(fp1);
        i++;
    }
    for (j=0;j<i;j++) {
        // remettre le pointeur fp3 au debut du fichier dico
        rewind(fp3);
        while (fgets(str_char,MAX_CODE,fp3)!=NULL){
            len_char=strlen(str_char);
            str_char[len_char]='\0';
            if (str_input[j]==str_char[0]){
                // chaque str_char[0] est un caractere
                for(m=2; m<len_char; m++){
                    // stocker directement dans le dictionnaire intermedaire (un bit par un)
                    fprintf(fp2,"%c", str_char[m]);
                }
            }
        }
    }
    rewind(fp2);
    printf("\n");
    while(fscanf(fp2, "%s", &str_code)!=EOF){
        fprintf(fp4,"%s",str_code);
        printf("%s",str_code);
    }
    printf("\nFinish encoding ! You can check it in the Encodage_huffman_final.txt. \n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}
// Question G
void compresser(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal){
    FILE* fp1=fopen(sInput,"r");
    FILE *fp2=fopen(sHuffman,"w+");
    FILE *fp3=fopen(dico,"r");
    FILE* fp4=fopen(sHuffmanFinal,"w+");
    int i=0,j=0,m=0,len_char;
    char str_input[MAX_INPUT];
    char str_char[MAX_CODE];
    char str_code[MAX_CODE];
    if (fp1==NULL || fp2==NULL || fp3==NULL || fp4==NULL) {
        printf("open error !\n");
        exit(1);
    }
    printf("\nStart to encode the Alice_input.txt... \n");
    char c1=fgetc(fp1);
    while (c1 != EOF){
        // depuis le premier caractere du fichier, on affiche des caracteres pour faire reference et voir le operation de l'encodage
        printf("%c",c1);
        str_input[i]=c1;
        c1=fgetc(fp1);
        i++;
    }
    for (j=0;j<i;j++) {
        // remettre le pointeur au debut du fichier dico, et chercher le code du caractere du fichier input
        rewind(fp3);
        // avec fgets(), on parcourt chaque ligne du fichier dico
        while (fgets(str_char,MAX_CODE,fp3)!=NULL){
            // resoudre le probleme du cas du caractere "retour a la ligne"
            len_char=strlen(str_char);
            str_char[len_char]='\0';
            // chaque ligne du dico devient un string, case 0 est le caractere, case 1 est l'espace
            // de la case 2 jusqu'a la fin du string est le code qu'on veut stocker dans le fichier sHuffman
            if (str_input[j]==str_char[0]){
                for(m=2; m<len_char; m++){
                    fprintf(fp2,"%c", str_char[m]);
                }
            }
        }
    }
    // du fichier sHuffman au fichier sHuffmanFinal, on va supprimer tous les "retour a la ligne"
    rewind(fp2);
    printf("\n");
    while(fscanf(fp2, "%s", &str_code)!=EOF){
        fprintf(fp4,"%s",str_code);
        // une operation supplementaire pour montrer que l'operation de l'encodage est bien faite
        // printf("%s",str_code);
    }
    printf("\nFinish encoding ! You can check it in the Alice_huffman_final.txt. \n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}
