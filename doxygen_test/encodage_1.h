/*****************************************************************//**
 * \file   encodage_1.h
 * \brief  Header du fichier encodage.c.
 * 
 * \author hugo GRANDJEAN hugo.grandjean@efrei.net 
 * \date   December 2020
 *********************************************************************/



#ifndef encodage_1_h
#define encodage_1_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 150000
#define MAX_CODE 10000


/**
 * \brief Traduire un texte e une suite binaire bas�e sur le dictionaire de Huffman.
 * \ param[in] des caract�res.
 *
 */
void Input2Binary_dico(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal);

/**
 * \brief �crire une fonction qui compresse un fichier.
 * \ param[in] des caract�res.
 */
void compresser(char* sInput, char* sHuffman, char* dico, char* sHuffmanFinal);

 
#endif /* encodage_1_h */
