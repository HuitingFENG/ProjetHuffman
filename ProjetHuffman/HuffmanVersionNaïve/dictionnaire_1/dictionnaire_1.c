
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnaire_1.h"

#define MAX_TREE_HT 100

struct HuffNode* newnewNode(char ch, int w) {
	struct HuffNode* temp = (struct HuffNode*)malloc(sizeof(struct HuffNode));
	temp->lchild = temp->rchild = NULL;
	temp->ch = ch;
	temp->w = w;
	return temp;
}
struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct HuffNode**)malloc(minHeap->capacity * sizeof(struct HuffNode*));
	return minHeap;
}
void changerHuffNode(struct HuffNode** a, struct HuffNode** b) {
	struct HuffNode* t = *a;
	*a = *b;
	*b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx) {
	int smallest = idx;
	int lchild = 2 * idx + 1;
	int rchild = 2 * idx + 2;
	if (lchild < minHeap->size && minHeap->array[lchild]->w < minHeap->array[smallest]->w)
		smallest = lchild;
	if (rchild < minHeap->size && minHeap->array[rchild]->w < minHeap->array[smallest]->w)
		smallest = rchild;
	if (smallest != idx) {
		changerHuffNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}
int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}
struct HuffNode* extractMin(struct MinHeap* minHeap) {
	struct HuffNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}
void insertMinHeap(struct MinHeap* minHeap, struct HuffNode* HuffNode) {
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && HuffNode->w < minHeap->array[(i - 1) / 2]->w) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = HuffNode;
}
void buildMinHeap(struct MinHeap* minHeap) {
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}
void printArr(int arr[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);
	printf("\n");
}
int isLeaf(struct HuffNode* root) {
	return !(root->lchild) && !(root->rchild);
}
struct MinHeap* createAndBuildMinHeap(char ch[], int w[], int size) {
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newnewNode(ch[i], w[i]);
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}
struct HuffNode* buildHuffmanTree(char ch[], int w[], int size) {
	struct HuffNode* lchild, * rchild, * top;
	struct MinHeap* minHeap = createAndBuildMinHeap(ch, w, size);
	while (!isSizeOne(minHeap)) {
		lchild = extractMin(minHeap);
		rchild = extractMin(minHeap);
		top = newnewNode('$', lchild->w + rchild->w);
		top->lchild = lchild;
		top->rchild = rchild;
		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}
void printCodes(struct HuffNode* root, int arr[], int top) {
	FILE* fp = fopen("C:\\Projet Huffman\\Test Files\\Alice_dico.txt", "w+");
	if (root->lchild) {
		arr[top] = 0;
		printCodes(root->lchild, arr, top + 1);
	}
	if (root->rchild) {
		arr[top] = 1;
		printCodes(root->rchild, arr, top + 1);
	}
	if (isLeaf(root)) {
		printf("%c : ", root->ch);
		fprintf(fp, "%c : ", root->ch);
		//printArr(arr,top);
		for (int i = 0; i < top; i++) {
			printf("%d", arr[i]);
			fprintf(fp, "%d", arr[i]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	fclose(fp);
}
void HuffmanCodes(char ch[], int w[], int size) {
	struct HuffNode* root = buildHuffmanTree(ch, w, size);
	int arr[100], top = 0;
	printCodes(root, arr, top);
}

void write_dictonnaire(struct HuffNode* L) {
	char ch[] = { ',', 'A', 'c', 'k', 'l', 'w','f','v','y','b','d','a','h','r','s','g','o','e','i','t','n',' ' };
	int w[] = { 1,1,1,1,1,1,2,2,2,3,3,4,4,4,4,6,7,8,9,9,10,20 };
	int size = sizeof(ch) / sizeof(ch[0]);
	HuffmanCodes(ch, w, size);
}