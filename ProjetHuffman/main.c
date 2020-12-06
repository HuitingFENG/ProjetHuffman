#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "occurrences_1.h"
#include "occurrences_1.c"

#include "arbre_1.h"
#include "arbre_1.c"

#include "dictionnaire_1.h"
#include "dictionnaire_1.c"

#include "encodage_1.h"
#include "encodage_1.c"

#include "decodage_1.h"
#include "decodage_1.c"

#define MAX_INPUT 150000
#define MAX_CODE 10000





// Fonction principale
int main(){
    printf("Bonjour, nous allons utiliser la methode de Huffman pour compresser et decompresser le fichier Alice_input.\n");
    printf("Veuillez bien respecter des consignes indiquees dans le guide d'utilisateur avant de lancer le programme.\n");
    Input2Binary("C:\\Projet Huffman\\Test Files\\Alice_input.txt","C:\\Projet Huffman\\Test Files\\Alice_binary.txt");
    printf("\nLa traduction du texte original au texte binaire :\n");
    printf("Les bits du fichier Alice_input : %d\n", compter("C:\\Projet Huffman\\Test Files\\Alice_input.txt"));
    printf("Les bits du fichier Alice_binary : %d\n", compter("C:\\Projet Huffman\\Test Files\\Alice_binary.txt"));
    struct HuffNode* L=list_occurrences("C:\\Projet Huffman\\Test Files\\Alice_input.txt");
    struct HuffNode* tree=creer_HuffmanTree(L);
    printf("\nL'arbre Huffman de la liste : \n");
    display_tree(tree);
    printf("\nLe dictionnaire de Huffman du fichier Alice_input : \n");
    write_dictonnaire(L,"C:\\Projet Huffman\\Test Files\\Alice_dico.txt");
    Input2Binary_dico("C:\\Projet Huffman\\Test Files\\Encodage_input.txt","C:\\Projet Huffman\\Test Files\\Encodage_huffman.txt","C:\\Projet Huffman\\Test Files\\Alice_dico.txt","C:\\Projet Huffman\\Test Files\\Encodage_huffman_final.txt");
    compresser("C:\\Projet Huffman\\Test Files\\Alice_input.txt","C:\\Projet Huffman\\Test Files\\Alice_huffman.txt", "C:\\Projet Huffman\\Test Files\\Alice_dico.txt","C:\\Projet Huffman\\Test Files\\Alice_huffman_final.txt");
    decompresser_petitTexte(tree,"C:\\Projet Huffman\\Test Files\\Alice_huffman_final.txt","C:\\Projet Huffman\\Test Files\\Alice_decodage.txt");
    //decompresser_grandTexte(tree,"C:\\Projet Huffman\\Test Files\\Alice_huffman_final.txt","C:\\Projet Huffman\\Test Files\\Alice_decodage.txt");
    printf("\nFinir !");
    free_list(L);
    free_hufftree(tree);
    return 0;
}



