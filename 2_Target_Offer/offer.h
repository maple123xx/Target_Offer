#ifndef offer_
#define offer_
#include"myNamespace.h"

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
int maxProductAfterCutting2(int length);
int numberOf1_1(int n);
int numberOf1_2(int n);
#endif // !offer_

