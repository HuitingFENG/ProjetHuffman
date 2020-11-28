
#ifndef DICTIONNAIRE_1
#define DICTIONNAIRE_1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct MinHeap {
	int size;
	int capacity;
	struct HuffNode** array;
};
struct HuffNode* newnewNode(char ch, int w);
struct MinHeap* createMinHeap(int capacity);
void changerHuffNode(struct HuffNode** a, struct HuffNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isSizeOne(struct MinHeap* minHeap);
struct HuffNode* extractMin(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct HuffNode* HuffNode);
void buildMinHeap(struct MinHeap* minHeap);
void printArr(int arr[], int n);
int isLeaf(struct HuffNode* root);
struct MinHeap* createAndBuildMinHeap(char ch[], int w[], int size);
struct HuffNode* buildHuffmanTree(char ch[], int w[], int size);
void printCodes(struct HuffNode* root, int arr[], int top);
void HuffmanCodes(char ch[], int w[], int size);
void write_dictonnaire(struct HuffNode* L);

#endif //