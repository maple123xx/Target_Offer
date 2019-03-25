#ifndef offer_
#define offer_
#include"myNamespace.h"

typedef double ElemType;

typedef multiset<int, greater<int>> intSet;	//greater是求最大的那个值，greater是降序排序，less是升序排序
typedef multiset<int, greater<int>>::iterator setIterator;

struct ListNode {
	ElemType data;
	ListNode *next;
};
ListNode *CreateListNode(ElemType value);
void ConnectListNodes(ListNode *pCurrent, ListNode *pNext);
void PrintList2(ListNode *pHead);
ListNode *MeetingNode(ListNode *pHead);
ListNode *EntryNode(ListNode *pHead);

struct ComplexNode {
	ElemType data;
	ComplexNode *next;
	ComplexNode *sibling;
};
ComplexNode* CreateNode(int nValue);
void BuildNodes(ComplexNode* pNode, ComplexNode* pNext, ComplexNode* pSibling);
void PrintList3(ComplexNode* pHead);
void CloneNodes(ComplexNode *pHead);
ComplexNode* ConnectSiblingNodes(ComplexNode *pHead);
ComplexNode* ReconnectNodes(ComplexNode *pHead);
ComplexNode* Clone(ComplexNode *pHead);

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
int TreeDepth(BTNode *root);
bool isBalanced1(BTNode *root);
bool isBalanced2(BTNode *root);
bool isBalanced2(BTNode *root, int *depth);
BTNode *KthNode(BTNode *root, int k);
BTNode *KthNodeCore(BTNode *root, int &k);
BTNode* Convert(BTNode* root);
void ConvertNode(BTNode* root, BTNode** lastNode);
//void Serialize(BTNode *root, ostream& output);

struct TreeNode {
	ElemType data;
	vector<TreeNode*> children;
};
TreeNode* CreateTreeNode(ElemType value);
void ConnectTreeNodes(TreeNode* parent, TreeNode* child);
void PrintNode(TreeNode* node);
void PrintTree(TreeNode* root);
bool getNodePath(TreeNode* root, TreeNode* node, list<const TreeNode*>& path);
const TreeNode* getLastCommomNode(const list<const TreeNode*>& path1, const list<const TreeNode*>& path2);
const TreeNode* getLastCommonParent(TreeNode* root, TreeNode* node1, TreeNode* node2);

bool Duplicate(int *A, int length, int *duplicate);
int Duplicate2(const int *A,int length);
int countRange(const int *A, int length, int start, int end);
bool Matrix_Find(int *A, int rows, int cols, int obj);
void ReplaceBlank(char str[]);
void copyBtoA(int *A, int *B, int a, int b);
//面试题9：用两个栈实现队列
template<typename T> class CQueue {
public:
	CQueue();
	~CQueue();
	void appendTail(const T& x);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template<typename T> CQueue<T>::CQueue(){}
template<typename T> CQueue<T>::~CQueue(){}
template<typename T> void CQueue<T>::appendTail(const T& x) {
	stack1.push(x);
}
template<typename T> T CQueue<T>::deleteHead() {
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack2.push(data);
			stack1.pop();
		}
	}
	if (stack2.size() == 0)
		throw new exception("queue is empty!");
	T head = stack2.top();
	stack2.pop();
	return head;
}

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
//面试题30：包含min函数的栈
template<typename T> class StackWithMin {
public:
	StackWithMin();
	~StackWithMin();
	void push(const T& value);
	void pop();
	const T& min() const;
private:
	stack<T> m_data;
	stack<T> m_min;
};
template<typename T> StackWithMin<T>::StackWithMin(){}
template<typename T> StackWithMin<T>::~StackWithMin() {}
template<typename T> void StackWithMin<T>::push(const T& value) {
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}
template<typename T> void StackWithMin<T>::pop() {
	m_data.pop();
	m_min.pop();
}
template<typename T> const T& StackWithMin<T>::min() const {
	//assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}
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
void Reverse(char *begin, char *end);
void ReverseSentence(char *data);
char* LeftRotateString(char *str, int n);
bool isContinue(int *data, int length);
void bucketSort(int *data, int length);
int LastRemaining(unsigned int n, unsigned int m);
int MaxDiff(const int *data, unsigned int length);
int SumWithBit(int num1, int num2);
void mutiply(const vector<double>& input, vector<double>& output);
long long StrToIntCore(const char *str, bool minus);
int StrToInt(const char* str);

bool match(const char* str, const char* pattern);
bool matchCore(const char* str, const char* pattern);
bool isNumberic(const char *str);
bool scanInteger(const char **str);
bool scanUnsignedInteger(const char **str);
void Permutation(char* str);
void Permutation(char* pStr, char* pBegin);
int NumberOf1Between1AndN_1(unsigned int n);
int NumberOf1_1(unsigned int i);
int NumberOf1Between1AndN_2(unsigned int n);
int NumberOf1_2(const char* str);
int PowerBase10(int n);
int LongestSubstringWithoutDuplication(const string& str);
//面试题五十九题目一：滑动窗口的最大值
vector<int> MaxInWindows(const vector<int>& num, int len);
//面试题五十九题目二：队列的最大值
template<typename T> class QueueWithMax {
public:
	QueueWithMax():currentIndex(0) {}
	void Push_back(T number) {
		if (!max_q.empty() && number > max_q.back().number)
			max_q.pop_back();
		InternalData interndata = { number,currentIndex };
		data_q.push_back(interndata);
		max_q.push_back(interndata);
		++currentIndex;
	}
	void Pop_front() {
		if (data_q.empty())
			throw new exception("queue is empty! ");
		if (data_q.front().index == max_q.front().index)//这个index的作用是当要pop的值是max_q和data_q一样的值时，就把它从max_q中pop出去
			max_q.pop_front();
		data_q.pop_front();
	}
	const T& max() {
		if (max_q.empty())
			throw new exception("queue is empty! ");
		return max_q.front().number;
	}
private:
	int currentIndex;
	struct InternalData
	{
		T number;
		int index;
	};
	deque<InternalData> data_q;
	deque<InternalData> max_q;
};
void PrintProbability(int number);
void Probability(int number, int *probability);
void Probability(int original, int current, int sum, int *probability);
// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
//方法一：
class Temp {
public:
	Temp() {
		++N;
		Sum += N;
	}
	static void Reset() {
		N = 0;
		Sum = 0;
	}
	static int getSum() {
		return Sum;
	}
private:
	static int N;
	static int Sum;
};
int Sum_Solution1(int n);
//方法二：
class A;

class B;
int Sum_Solution2(int n);
//方法三：
typedef int (*fun)(int);//定义一个函数指针类型 fun
int Solution3_Teminator(int n);
int Sum_Solution3(int n);

#endif // !offer_

