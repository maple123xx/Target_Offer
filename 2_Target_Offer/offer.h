#ifndef offer_
#define offer_
#include"myNamespace.h"

typedef double ElemType;

typedef multiset<int, greater<int>> intSet;	//greater是求最大的那个值，greater是降序排序，less是升序排序
typedef multiset<int, greater<int>>::iterator setIterator;

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
void LevelPrint(BTNode *root);
void LevelPrint2(BTNode *root);
void LevelPrint3(BTNode *root);


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
bool isPopOrder(const int *pPush, const int *pPop, int length);
bool VerifySequenceOfBST(int Sequence[], int length);
bool CheckMoreThanHalf(int *num, int length, int number);
int Partition(int *num, int start, int end);
int MoreThanHalfNum(int *num, int length);
int MoreThanHalfNum2(int *num, int length);
void GetLeastNumber(int *input, int n, int *output, int k);
void GetLeastNumber2(const vector<int>& data, intSet& leastNumbers, int k);
template<typename T>
class DynamicArray {//依次输入数到数据流中，
public:
	void insert(T num) {
		if (((min.size() + max.size()) & 1) == 0) {	//数组总数目为偶数，应把新数据插入最小堆
			if (max.size() > 0 && num < max[0]) {	//应保证最大堆的所有数据小于最小堆，如果这个数据比最大堆的一些数据要小，
				max.push_back(num);					//就把最大堆的最大数据拿出来给最小堆
				push_heap(max.begin(), max.end(), less<T>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else {
			if (min.size() > 0 && num > min[0]) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}
	T GetMidium() {
		size_t size = min.size() + max.size();
		if (size == 0) {
			throw exception("No numbers are available");
		}
		T median = 0;
		if ((size&1)==1) {
			median=min[0];
		}
		else {
			median = (min[0] + max[0])/2;
		}
		return median;
	}
private:
	vector<T> min;
	vector<T> max;
};
int FindGreatestSumOfSubArray(int *pData, int length);
int NumberOf1Between1AndN(unsigned int n);
int NumberOf1(unsigned int i);
int digitAtIndex(int index);
int countOfIntegers(int digit);
int digitAtIndex(int index, int digit);
int beginNumber(int digit);
int digitAtIndex2(int n);
int digit2(int current);
int getMaxValue_solution1(const int* values, int rows, int cols);
int getMaxValue_solution2(const int* values, int rows, int cols);
int GetUglyNumber_Solution1(int index);
bool isUglyNumber(int number);
int GetUglyNumber_Solution2(int index);
int Min(int number1, int number2, int number3);
char FirstNotRepeatingChar(char* pString);
void DeleteFirstString(char string1[], char string2[]);
void delete_char(char str[], char target);
//面试题50题目二：字符流中第一个只出现一次的字符
class CharStatistics{
public:
	CharStatistics() : index(0){
		for (int i = 0; i < 256; ++i)
			occurrence[i] = -1;
	}

	void Insert(char ch){
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;

		index++;
	}
	char FirstAppearingOnce(){
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();	//返回 编译器允许的int型数的最大值，即2147483647
		for (int i = 0; i < 256; ++i){
			if (occurrence[i] >= 0 && occurrence[i] < minIndex){
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
		return ch;
	}
private:
	// occurrence[i]: A character with ASCII value i;
	// occurrence[i] = -1: The character has not found;
	// occurrence[i] = -2: The character has been found for mutlple times
	// occurrence[i] >= 0: The character has been found only once
	int occurrence[256];
	int index;	//index用来索引字符流的字符,大小没有意义，只要大于等于0，都表示只出现一次
};
void Delete_Repeat(char str[]);
bool Anagram(char str1[], char str2[]);
int GetNumberOfK(int *data, int length, int k);
int GetFirstK(int *data, int k, int length, int start, int end);
int GetLastK(int *data, int k, int length, int start, int end);
int GetMissingNumber(int *data, int length);
int GetNumberSameAsIndex(int *data, int length);
void FindNumberAppearOnce(int *data, int length, int &num1, int &num2);
unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexOf1);
int FindNumberAppearOnce(int *data, int length);
bool SumIsS(int *data, int length, int s, int *num1, int *num2);
void ContinuousSequenceIsS(int sum);
void printSequence(int small, int big);
#endif // !offer_

