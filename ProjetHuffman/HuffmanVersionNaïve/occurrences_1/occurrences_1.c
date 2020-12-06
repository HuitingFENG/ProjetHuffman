#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "occurrences_1.h"



// Question A
void Input2Binary(char* sInput, char* sBinary){
    char str[MAX_INPUT];
    int cc, n, i, j, k;
    FILE* fp1 = fopen(sInput, "r");
    FILE* fp2 = fopen(sBinary, "w");
    if (fp1 == NULL || fp2 == NULL){
        printf ("Open error ! \n");
        exit(1);
    }
    for (n=0 ; n<MAX_INPUT ; n++){
        str[n]='\0';
    }
    for (i=0 ; i<MAX_INPUT ; i++){
        // stocker chaque caractere du fichier sInput dans str[]
        fscanf(fp1,"%c", &str[i]);
    }
    for (k=0 ; k<MAX_INPUT && str[k]!='\0' ; k++)
    {
        cc = str[k];
        // utiliser fprintf() pour stocker les bits de chaque caractere dans le fichier sBinary
        // stocker un bit par un (8 bits chaque caractere donc faut 8 fois de stockage pour un seul caractere)
        for(j=7 ; j>=0 ; j--){
            // utiliser des operateurs pour les manipulations binaires ('<<' est superieur a '&' dans l'ordre de manipulation)
            // '>>' (Bitwise right shift) : deplacer le binaire de chaque caractere a droit (7, 6, 5, 4, 3, 2, 1, 0 places)
            // '&' (Bitwise AND operator) : 0 & 0 = 0 ; 0 & 1 = 0 ; 1 & 0 = 0 ; 1 & 1 = 1 (on compare chaque bit et le resultat est soit 1 soit 0)
            fprintf(fp2, "%d", cc >> j & 1);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
// Question B
int compter(char* sInput){
    char cc;
    int count=0;
    // fp est un pointeur du fichier sInput
    FILE* fp=fopen(sInput,"r");
    if (fp==NULL){
        printf("Open error !\n");
        exit(1);
    }
    // utiliser fgetc pour parcourir chaque caractere du fichier sInput
    // compter jusqu'à la fin du fichier sInput (EOF)
    while((cc=fgetc(fp))!=EOF){
        count++;
    }
    fclose(fp);
    return count;
}


// Question C
struct HuffNode* newNode(int ww, char cc)
{
    // creer une liste de noeuds (pile) pour une liste d'occurrences
    struct HuffNode* stackNode = (struct HuffNode*)malloc(sizeof(struct HuffNode));
    stackNode->w = ww;
    stackNode->ch = cc;
    stackNode->next = NULL;
    return stackNode;
}
int is_empty(struct HuffNode* root)
{
    if(root==NULL){
        return 1;
    }
    else {
        return 0;
    }
}
void push(struct HuffNode** root, int ww, char cc)
{
    // enpiler pour ajouter un nouveau noeud chaque fois dans une liste de noeuds
    struct HuffNode* stackNode = newNode(ww,cc);
    stackNode->next = *root;
    *root = stackNode;
    // pouvoir utiliser un printf suivant pour tester si un noeud est bien enpile/ajoute dans la liste de noeuds
    // printf("%c %d pushed to stack\n", cc, ww);
}
void display_pile(struct HuffNode* L){
    if(L==NULL){
        return;
    }
    printf("\nLa liste d'occurrences du fichier Alice_input : \n");
    while (L!=NULL){
        printf("%c : %d\n", L->ch, L->w);
        L=L->next;
    }
}
struct HuffNode* sort_pile(struct HuffNode* root){
    // une fonction pour tirer une liste de noeuds en fonction de nombre d'occurrences
    // une fonction sert aussi à la question J dans la troisieme partie du Projet Huffman (la version optimisee)
    struct HuffNode* head,*pp,*qq,*pp_max,*qq_max;
    // head est la pile à retourner dans cette fonction
    head = NULL;
    while(root != NULL){
        // la direction de la pile est : ...un noeud -> noeud qq (root) -> noeud pp (root->next) -> un autre noeud...
        // chaque fois on compare les deux noeuds successifs et on les tire avec l'ordre, ainsi que la condition est quand pp n'est pas NULL
        for(qq = pp_max = root, pp = root->next; pp ; qq = pp, pp = pp->next){
            // comparer le nombre d'occurrences de deux noeuds
            if(pp->w > pp_max->w){
                pp_max = pp;
                qq_max = qq;
            }
        }
        // apres la boucle for, on obtient la valeur de pp_max et la valeur de qq_max, mais il faut toujours pp_max est grande à qq_max
        // parce que l'on ne veut que la plus grande valeur, dans notre cas est pp_max, et on va que stocker pp_max dans la pile à retourner
        // le if_else suivant est pour mettre pp_max au root afin de recommencer la boucle while
        if(pp_max == root){
            root = root->next;
        }
        else{
            qq_max->next = pp_max->next;
        }
        // ces deux lignes sont pour stocker le noeud pp_max chaque fois dans head qui est aussi une pile
        pp_max->next = head;
        head = pp_max;
    }
    return head;
}
struct HuffNode* list_occurrences(char* sInput){
    // on cree et initialise la liste de frequence qui sert à stocker le nombre d'occurrences de chaque caractere du fichier sInput
    int list_frequency[MAX_INPUT]={0};
    int i, j, fileSize;
    // on stock le contenu complet du fichier dans strText
    char* strText;
    struct HuffNode* root=NULL;
    FILE* fp=fopen(sInput,"r");
    if(fp == NULL){
        printf ("Open error ! \n");
        exit(1);
    }
    // on met le pointeur fp à la fin du fichier (SEEK_END) avec fonction predefinie fseek
    // int fseek (FILE* stream, long int offset, int fromwhere)
    fseek(fp,0,SEEK_END);
    // on calcul le nombre de caractere du fichier sInput avec ftell
    // ftell() en C sert à trouver la distance entre la position du pointeur et la position du bebut du fichier
    // long ftell (FILE* pointeur)
    // ftell() retourne un nombre
    fileSize=ftell(fp);
    // printf("%d\n",fileSize);
    // on remet le pointeur au debut du fichier sInput (SEEK_SET)
    fseek(fp, 0, SEEK_SET);
    strText=(char*)malloc(fileSize*sizeof(char));
    // fread lit le nombre d'elements de taille octets a partir du flux d'entree et les stocke dans la memoire tampon
    fread(strText, fileSize, sizeof(char), fp);
    strText[fileSize]='\0';
    // printf("%s\n", strText);
    // strText[] stocke tous les caractere du fichier, du debut a la fin du fichier, on compte les nombres des occurrences avec un boucle for
    // il faut parcourir le fichier, donc c'est une methode moins rapide
    // par ex si strText[i] = 'A', on compte combien de fois de 'A' et stock un chiffre dans la liste de frequence, si on revoit 'A', on ajoute 1 fois
    for (int i=0; strText[i]!='\0';i++){
        list_frequency[strText[i]]++;
    }
    // la boucle suivante sert a ajouter un noeud dans la pile
    for(int i=0;i<MAX_INPUT;i++){
        if (list_frequency[i] != 0){
            // ici, i est le caractere, list_frequency [i] est son nombre d'occurrences
            push(&root, list_frequency[i], i);
            //printf("%c : %d \n", i, list_frequency[i]);
        }
    }
    struct HuffNode* new_root=sort_pile(root);
    // cette fonction sert a renvoyer une liste d'occurrences, mais on affiche ici la pile tiree
    // on la tire pour faciliter d'autres operations prochaines
    display_pile(new_root);
    fclose(fp);
    return new_root;
}
void free_list(struct HuffNode* L){
    if (L != NULL){
        free_list(L->next);
        free(L);
    }
}
