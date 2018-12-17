#ifndef offer_
#define offer_
#include"myNamespace.h"

typedef double ElemType;
struct BTNode {
	ElemType data;
	BTNode *lchild;
	BTNode *rchild;
	BTNode *parent;
};
BTNode *CreateBTNode(ElemType data);
void ConnectTreeNode(BTNode *parent, BTNode *lchild, BTNode *rchild);
void PreOrder(BTNode *root);
BTNode *NextNode(BTNode *pNode);
void DestroyTree(BTNode *root);
bool HasSubtree(BTNode *root1, BTNode *root2);
bool DoesTree1HaveTree2(BTNode *root1, BTNode *root2);
bool isSymmetry(BTNode *root);
bool isSymmetry(BTNode *root1, BTNode *root2);


bool Duplicate(int *A, int length, int *duplicate);
int Duplicate2(const int *A,int length);
int countRange(const int *A, int length, int start, int end);
bool Matrix_Find(int *A, int rows, int cols, int obj);
void ReplaceBlank(char str[]);
void copyBtoA(int *A, int *B, int a, int b);
long long Fibonacci(unsigned int n);
int Rotate_Min(int *A, int length);
int MinSequenceFind(int *A, int low, int high);
bool HasPath(const char* matrix, int rows, int columns, const char* str);
bool HasPathCore(const char* matrix, int rows, int i, int cols, int j, const char* str,int &pathLength, bool *visited);
int robotRoad(int threshold, int rows, int cols);
int robotRoadCore(int threshold, int rows, int cols, int i, int j, bool *visited);
bool check(int threshold, int rows, int cols, int i, int j, bool *visited);
int getDigitSum(int i);
int maxProductAfterCutting1(int length);
double maxProductAfterCutting2(int length);
int numberOf1_1(int n);
int numberOf1_2(int n);
bool isPowerOf2(int n);
int changeBit(int m, int n);
double power(double base, int exponent, bool &invalidInput);
double PowerWithUnsignedExponent1(double base, unsigned int absExponent);
double PowerWithUnsignedExponent2(double base, unsigned int absExponent);
void Print1ToMaxOfNDigits_1(int n);
void PrintNumber(char *number);
bool Increment(char* number);
void Print1ToMaxOfNDigits_2(int n);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
#endif // !offer_

