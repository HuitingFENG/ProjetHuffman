/***********************************************//**
 * \file   dictionnaire_1.h
 * \brief  Header of the dictionary file
 * 
 * \author Yasmine MERINE yasmine.merine@efrei.net
 * \date   November 2020
 *********************************************************************/
#ifndef dictionnaire_1_h
#define dictionnaire_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

 /**
 * \typedef struct HuffNode
 * \brief un noeud de Huffman.
 */
typedef struct HuffNode {
    int w; /**< le nombre d'occurences d'une caractere (= weight) */
    char ch;  /**< ch est le caractere (= character) */
    // utiliser next pour faire une LSC et une pile
    struct HuffNode* next; /**<  utiliser next pour faire une LSC et une pile */
    struct HuffNode* lchild; /**< pointeur vers l'enfant gauche */
    struct HuffNode* rchild; /**< pointeur vers l'enfant droit */
}HHuffNode, * HuffTree;




/**
* \typedef struct MinNode
* \brief structure permettant la construction de l'arbre.
*/
typedef struct MinNode {
    struct HuffNode** tab; /**< tableau des noeuds */
    int size; /**< taille */
    int cap; /**< capacité */
}MinNode;

typedef struct MinNode {
    struct HuffNode** tab;
    int size;
    int cap;
}MinNode;


/**
 * \brief afficher les codes de Huffaman.
 * \param[in] un arbre de Huffman, un tableau, un parent, un fichier fp
 *
 */
void printCodes(struct HuffNode* root, int arr[], int parent, FILE* fp);

 
/**
 * \brief créer un arbre de Huffman et afficher le dictionnaire du fichier prit en paramètre.
 * \param[in] pointeur de la liste, fichier fp
 *
 */
void HuffmanCodes(struct HuffNode* L, FILE* fp);

/**
 * \brief écrire le dictionnaire dans le fichier.
 * \param[in] pointeur de la liste, charactère du dictionnaire
 *
 */
void write_dictonnaire(struct HuffNode* L, char* dico);




#endif /* dictionnaire_1_h */
