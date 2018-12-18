#ifndef HuffmanTree_
#define HuffmanTree_
#include"myNamespace.h"

typedef int ElemType;
struct BTNode {
	ElemType data;
	BTNode *lchild;
	BTNode *rchild;
};

BTNode *huffman(ElemType A[], int n);
void PreOrder(BTNode *root);
ElemType WPL(BTNode *root, int len);
void HuffmanCoding(BTNode *root, int len);
#endif // !HuffmanTree_

