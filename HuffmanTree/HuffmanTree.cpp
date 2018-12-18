#include"HuffmanTree.h"

BTNode *huffman(ElemType A[], int n) {
	BTNode **b = (BTNode **)malloc(n * sizeof(BTNode));
	BTNode *q=NULL;
	int i, j;
	for (i = 0; i < n; ++i) {	//初始化具有n个节点的森林
		b[i] = (BTNode *)malloc(sizeof(BTNode));
		b[i]->data = A[i];
		b[i]->lchild = b[i]->rchild = NULL;
	}
	for (i = 1; i < n; ++i) {	//进行 n-1 次循环建立哈夫曼树  
		int k1 = -1, k2;		//k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标  
		for (j = 0; j < n; ++j) {	//让k1初始指向森林中第一棵树，k2指向第二棵  
			if (b[j] && k1 == -1) {	//判断b[j]是否为空重要
				k1 = j;
				continue;
			}
			if (b[j]) {
				k2 = j;
				break;
			}
		}
		for (j = k2; j < n; ++j) {	//从当前森林中求出最小权值树和次最小  
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
		b[k1] = q;		//重要，相当把q的值于加入数组中
		b[k2] = NULL;	//重要，赋为空，下一轮不要这个值了
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
	static int a[10];//定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一 
	if (root) {
		if (!root->lchild && !root->rchild) {
			int i = 0;
			cout << "节点权值为" << root->data << "的编码为；";
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