/*****************************************************************//**
* \file decodage_1.h
* \brief Header of the library allowing the decodage.
*
* \author   Huiting FENG    huiting.feng@efrei.net
* \date 11 december 2020
* \date September 2020 *********************************************************************/

#ifndef decodage_1_h
#define decodage_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000

/**
 * \brief pour décompresser un court texte Encodage_huffman_final. 
 * \param[in] un fichier texte Encodage_huffman_final, un fichier texte Encodage_huffman_decodage, un arbre Hufftree.
 */
void decompresser_petitTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage);

/** 
* \brief pour décompresser un grand texte Alice_input
* \param[in] un fichier texte Alice_huffman_final, un fichier texte Alice_decodage, un arbre Hufftree
*/
void decompresser_grandTexte(struct HuffNode* ht, char* sHuffmanFinal, char* sDecodage);


#endif /* decodage_1_h */


