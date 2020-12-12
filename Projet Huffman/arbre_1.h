/*****************************************************************//**
* \file arbre_1.h
* \brief Header du fichier arbre_1.c.
*
* \author Aminetou JELEDI aminetou.jeledi@efrei.net
* \date Decembre 2020
*********************************************************************/

#ifndef arbre_1_h
#define arbre_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

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
}HuffNode, *HuffTree;

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

typedef struct MinNode {
    struct HuffNode** tab; 
    int size; 
    int cap; 
}MinNode;

/**
* \typedef struct MinNode
* \brief structure permettant de cr�er l'arbre 
*/
typedef struct MinNode {
    struct HuffNode** tab; /**< tableau de type HuffNode/
    int size; /**<taille>*/
    int cap; /**<capacit�>*/
}MinNode;


struct HuffNode* newnewNode(char cc, int ww);
/*
* \brief cr�er un noeud de Huffman.
* \param[in] un caract�re et sa fr�quence.
* \return un noeud de Huffman.
* 
*/
void minimize(struct MinNode* minNode, int pos);
/*
* \brief recherche le noeud qui a la plus petite fr�quence les ous arbres gauche et droite .
* \param[in] un noeud MinNode et la taille de son tableau.
* 
*
*/
struct HuffNode* get_minNode(struct MinNode* minNode);
/*
* \brief appelle la fonction minimize.
* \param[in] un arbre MinNode.
* \return le noeud ayant la fr�quence la plus petite
*
*/
void insert_minNode(struct MinNode* minNode, struct HuffNode* parent);
/*
* \brief ins�re un noeud dans un tableau  de Huffman.
* \param[in] un arbre MinNode et le noeud � ins�rer.
* 
*
*/
struct MinNode* create_list_minNode(struct HuffNode* L);
/*
* \brief cr�er une liste contenant tous les carat�res et leurs fr�quences.
* \param[in] un noeud de Huffman.
* \return la liste des noeuds.
*
*/
struct HuffNode* creer_HuffmanTree(struct HuffNode* L);
/*
* \brief fonction principale qui permet de cr�er l'arbre de Huffman.
* \param[in] un noeud de Huffman.
* \return l'arbre de Huffman rang�.
*
*/
void display_tree(struct HuffNode* tree);
/*
* \brief afficher l'arbre cr�e dans la fonction principale.
* \param[in] l'arbre de Huffman cr�e.
* 
*
*/
void free_hufftree(struct HuffNode* ht);
/*
* \brief lib�re l'arbre de Huffman cr�e.
* \param[in] un arbre de Huffman.
*
*
*/


#endif /* arbre_1_h */
