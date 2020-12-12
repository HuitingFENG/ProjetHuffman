/*****************************************************************//**
 * \file occurrences_1.h
 * \brief header du fichier occurence de la premiere partie du projet Huffman
 *
 * \author sugitha nadarjah sugitha.nadarajah@efrei.net
 * \date decembre 2020 
 *********************************************************************/
#ifndef occurrences_1_h
#define occurrences_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

 /**
 * \typedef struct HuffNode
 * \brief noeud de l'arbre de Huffman.
 */
typedef struct HuffNode {
    // w est le nombre d'occurences d'une caractere (= weight)
    int w;
    // ch est le caractere (= character)
    char ch;
    // utiliser next pour faire une LSC et une pile
    struct HuffNode* next;
    // utiliser l'enfant gauche et l'enfant droit pour faire un arbre Huffman
    struct HuffNode* lchild;
    struct HuffNode* rchild;
}HuffNode, * HuffTree;


/**  
* \brief un  fichier texte en binaire.
* \param[in] un fichier texte.
 */
void Input2Binary(char* sInput, char* sBinary);
/**  
* \brief compter le nombre de caractere.
* \param[in] un fichier texte.
* \return count, le nombre de caractere present dans le fichier texte.
 */
int compter(char* sInput);
/**  
* \brief creer un noeud de huffman.
* \param[in] une occurrence et un caractere.
* \return un noeud.
 */
struct HuffNode* newNode(int ww, char cc);

/** 
* \brief verifier si la liste est vide ou pas.
* \param[in] une liste.
* \return un entier, 1 si elle est vide, 0 sinon.
 */
int is_empty(struct HuffNode* root);
/**  
* \brief empiler un noeud dans une liste.
* \param[in] la liste, et le noeud à empiler

 */
void push(struct HuffNode** root, int ww, char cc);
/**  
* \brief afficher une liste.
* \param[in] la liste.
 */
void display_pile(struct HuffNode* L);
/**  
* \brief trier la liste par ordre croissant.
* \param[in] une liste.
* \return head.
 */
struct HuffNode* sort_pile(struct HuffNode* root);
/**  
* \brief fonction c du projet huffman, sert à avoir une liste d'occurrence.
* \param[in] un fichier texte.
* \return la liste triee.
 */
struct HuffNode* list_occurrences(char* sInput);
/**  
* \brief liberer espace.
* \param[in] liste.
 */

void free_list(struct HuffNode* L);



#endif /* occurrences_1_h */
