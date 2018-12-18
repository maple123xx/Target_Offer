#include"HuffmanTree.h"

int main() {
	ElemType A[] = { 9,12,6,3,5,15 };
	BTNode *q = huffman(A, 6);
	PreOrder(q);
	cout << endl;
	cout << "带权路径和为：" << WPL(q, 0) << endl;
	HuffmanCoding(q, 0);
	return 0;
}