#include"HuffmanTree.h"

BTNode *huffman(ElemType A[], int n) {
	BTNode **b = (BTNode **)malloc(n * sizeof(BTNode));
	BTNode *q=NULL;
	int i, j;
	for (i = 0; i < n; ++i) {	//��ʼ������n���ڵ��ɭ��
		b[i] = (BTNode *)malloc(sizeof(BTNode));
		b[i]->data = A[i];
		b[i]->lchild = b[i]->rchild = NULL;
	}
	for (i = 1; i < n; ++i) {	//���� n-1 ��ѭ��������������  
		int k1 = -1, k2;		//k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�  
		for (j = 0; j < n; ++j) {	//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���  
			if (b[j] && k1 == -1) {	//�ж�b[j]�Ƿ�Ϊ����Ҫ
				k1 = j;
				continue;
			}
			if (b[j]) {
				k2 = j;
				break;
			}
		}
		for (j = k2; j < n; ++j) {	//�ӵ�ǰɭ���������СȨֵ���ʹ���С  
			if (b[j]) {
				if (b[j]->data < b[k1]->data) {
					k2 = k1;
					k1 = j;
				}
				else if (b[j]->data < b[k2]->data) {
					k2 = j;
				}
			}
		}
		q = (BTNode *)malloc(sizeof(BTNode));
		q->data = b[k1]->data + b[k2]->data;
		q->lchild = b[k1];
		q->rchild = b[k2];
		b[k1] = q;		//��Ҫ���൱��q��ֵ�ڼ���������
		b[k2] = NULL;	//��Ҫ����Ϊ�գ���һ�ֲ�Ҫ���ֵ��
	}
	free(b);
	return q;

}
void PreOrder(BTNode *root) {
	if (root) {
		cout << root->data;
		if (root->lchild||root->rchild) {
			cout << "(";
			PreOrder(root->lchild);
			if (root->rchild)
				cout << ", ";
			PreOrder(root->rchild);
			cout << ")";
		}
	}
}
ElemType WPL(BTNode *root, int len) {
	if (!root)
		return 0;
	else{
		if (!root->lchild && !root->rchild)
			return root->data*len;
		else
			return WPL(root->lchild, len + 1) + WPL(root->rchild, len + 1);

	}
}
void HuffmanCoding(BTNode *root, int len) {
	static int a[10];//���徲̬����a������ÿ��Ҷ�ӵı��룬���鳤������������ȼ�һ 
	if (root) {
		if (!root->lchild && !root->rchild) {
			int i = 0;
			cout << "�ڵ�ȨֵΪ" << root->data << "�ı���Ϊ��";
			for (i = 0; i < len; ++i) {
				cout << a[i];
			}
			cout << endl;
		}
		else {
			a[len] = 0;
			HuffmanCoding(root->lchild, len + 1);
			a[len] = 1;
			HuffmanCoding(root->rchild, len + 1);
		}
	}
}