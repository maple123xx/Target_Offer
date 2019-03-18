#include"offer.h"

//������3
//1.�ҳ�����������һ���ظ�������
bool Duplicate(int *A, int length, int *duplicate) {
	//��һ��O(n)��ʱ�䣬O(1)�Ŀռ�
	if (length <= 0)
		return false;
	for (int i = 0; i < length; ++i) {
		if (A[i] < 0 || A[i] >= length)
			return false;
	}
	for (int i = 0; i < length; ++i) {
		while (A[i] != i) {
			if (A[i] == A[A[i]]) {
				*duplicate = A[i];
				return true;
			}
			else {
				//std::swap(A[i], A[A[i]]);
				int temp = A[i];
				A[i] = A[temp];
				A[temp] = temp;
			}
		}
	}
	return false;
	//������Ͱ������O(n)��ʱ���ڣ�O(n)�Ŀռ�
	/*int i;
	int B[100] = {0};
	for (i = 0; i < length; ++i) {
		++B[A[i]];
	}
	for (i = 0; i < length; ++i) {
		if (B[i] >= 2) {
			*duplicate = i;
			return true;
		}
	}
	return false;*/
}
//2.���޸����飬�ҳ���������һ���ظ�������
int Duplicate2(const int *A,int length) {//����Ϊconst�Ƿ�ֹ�޸�
	//����Ϊn+1�����飬Ԫ��Ϊ1~n������
	//O(nlogn)��ʱ�䣬O(1)�Ŀռ�
	//�÷��������ҳ������ظ�������
	int start = 1;
	int end = length - 1;
	while (end >= start) {
		//int mid = ((end - start) >> 1) + start;//>>1���ǳ���2��������mid�ķ�ʽ�����ڴ�1��ʼ�����飬��0��ʼ�Ͳ�������
		int mid = (start + end) / 2;
		int count = countRange(A, length, start, mid);
		if (start == end) {
			if (count > 1) {
				return start;
			}
			else {
				break;
			}
		}
		if (count > mid)
			end = mid;
		else
			start = mid + 1;
	}
	return -1;

}
int countRange(const int *A, int length, int start, int end) {
	int count=0;
	for (int i = 0; i < length; ++i) {
		if (A[i] >= start&&A[i] <= end) {
			++count;
		}
	}
	return count;
}
//������4���ڶ�ά��������ָ������(ÿһ�д����ҵ��������ϵ��µ���)
bool Matrix_Find(int *A, int rows,int cols,int obj) {
	int row = 0,col=cols-1;
	bool found = false;
	while (row <= rows - 1 && col >= 0) {
		if (A[row*cols + col] == obj) {//�����Ͻǵ�����ʼ�Ƚ�
			found = true;
			break;
		}
		else if (A[row*cols + col] > obj)
			--col;
		else
			++row;
	}
	return found;
}
//������5���滻�ո�
void ReplaceBlank(char str[]) {
	//���ո��滻Ϊ%20�����������ַ���Ҫ�����Ǻ�����ַ������ԴӺ���ǰ����
	//O(n)��ʱ�䣬O(1)�Ŀռ�
	int i=0;
	int blank = 0;
	int oldLength=0;
	int newLength;
	while (str[i] != '\0') {
		++oldLength;
		if (str[i] == ' ')
			++blank;
		++i;
	}
	newLength = oldLength + blank * 2;
	int indexOld = oldLength;
	int indexNew = newLength;
	while (indexOld >= 0 && indexNew > indexOld) {
		if (str[indexOld] == ' ') {
			str[indexNew--] = '0';
			str[indexNew--] = '2';
			str[indexNew--] = '%';
		}
		else {
			str[indexNew--] = str[indexOld];
		}
		--indexOld;
	}
}
void copyBtoA(int *A, int *B,int a ,int b) {
	//������5�������Ŀ��A��B�����������飬A�㹻�󣬰�A,B�ϲ����Һϲ�����������
	//�Ӻ���ǰ���ƣ��Ϳ��Լ����ƶ�����
	int indexA = a - 1;
	int indexB = b - 1;
	int n = a + b - 1;
	while (indexA >= 0 && indexB >= 0) {
		if (A[indexA] >= B[indexB]) {
			A[n--] = A[indexA--];
		}
		else {
			A[n--] = B[indexB--];
		}
	}
	while (indexA >= 0) {
		A[n--] = A[indexA--];
	}
	while (indexB >= 0) {
		A[n--] = A[indexB--];
	}
}
//������6����ͷ��β��ӡ���������ݽṹ�����Ѿ�д����
//������7���ؽ��������������ݽṹ�����Ѿ�д����
//������8������������һ���ڵ�
BTNode *CreateBTNode(ElemType data) {
	BTNode *pNode = new BTNode();
	pNode->data = data;
	pNode->parent = NULL;
	pNode->lchild = NULL;
	pNode->rchild = NULL;
	return pNode;
}
void ConnectTreeNode(BTNode *parent, BTNode *lchild, BTNode *rchild) {
	if (parent) {
		parent->lchild = lchild;
		parent->rchild = rchild;
		if (lchild)
			lchild->parent = parent;
		if (rchild)
			rchild->parent = parent;
	}
}
void PreOrder(BTNode *root) {
	if (root) {
		cout << root->data << '\t';
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
BTNode *NextNode(BTNode *pNode) {
	//��ĳ���ڵ�������������һ���ڵ�
	if (!pNode)
		return NULL;
	BTNode *pNext = NULL;
	if (pNode->rchild) {	//����ýڵ����Һ��ӣ�����һ���ڵ�Ϊ�������������½ڵ�
		BTNode *pRight = pNode->rchild;
		while (pRight->lchild){
			pRight = pRight->lchild;
		}
		pNext = pRight;
	}
	else if (pNode->parent) {	//�����û���Һ���
		BTNode *pCurrent = pNode;
		BTNode *pParent = pNode->parent;
		while (pParent&&pParent->rchild == pCurrent) {//�����������ڵ�����ӣ�����һ���ڵ�������ĸ��ڵ�
			pCurrent = pParent;						  //����һֱ���ϱ�����ֱ����ǰ�������ڵ������
			pParent = pParent->parent;
		}
		pNext = pParent;
	}
	return pNext;
}
void DestroyTree(BTNode *root) {
	if (root) {
		BTNode *left = root->lchild;
		BTNode *right = root->rchild;
		delete root;
		root = NULL;
		DestroyTree(left);
		DestroyTree(right);
	}
}
//������9��������ջʵ�ֶ��У�д��ͷ�ļ�����
//������10��쳲���������
long long Fibonacci(unsigned int n) {
	/*if (n == 0)	//�ݹ飺Ч�ʵ�
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);*/
	if (n == 0)		//�ǵݹ�
		return 0;
	if (n == 1)
		return 1;
	long long a = 0;
	long long b = 1;
	long long c;
	for (unsigned int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
//������ʮһ����ת�������С����
int Rotate_Min(int *A, int length) {//[3,4,5,1,2]
	int low = 0, high = length - 1;
	int mid = low;	//�����������ѭ��һ��Ҳ����ȥ��ֱ�ӷ�����СֵA[low],���԰�mid��ʼ��Ϊlow
	while (A[low] >= A[high]) {
		if (high - low == 1) {
			mid = high;
			break;
		}
		mid = (low + high) / 2;
		if (A[low] == A[mid] && A[high] == A[mid]) {//��������ȣ���ֻ��˳����ң���[1,0,1,1,1]��[1,1,1,0,1]
			return MinSequenceFind(A, low, high);
		}
		if (A[mid] >= A[low])
			low = mid;
		else if (A[mid] <= A[high])
			high = mid;
	}
	return A[mid];
}
int MinSequenceFind(int *A, int low,int high) {
	int min = A[low];
	for (int i = low+1; i <= high; ++i) {
		if (A[i] < min)
			min = A[i];
	}
	return min;
}
//������ʮ���������е�·�������ݷ�
bool HasPath(const char* matrix, int rows, int cols, const char* str) {
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (HasPathCore(matrix, rows, i, cols, j, str, pathLength, visited))
				return true;
		}
	}
	delete[] visited;
	return false;
}
bool HasPathCore(const char* matrix, int rows, int i, int cols, int j, const char* str,int &pathLength, bool *visited) {
	if (str[pathLength] == '\0')//�ݹ���ֹ����
		return true;
	bool hasPath = false;
	if (i >= 0 && i < rows && j >= 0 && j < cols && matrix[i*cols + j] == str[pathLength] && !visited[i*cols + j]) {
		++pathLength;
		visited[i*cols + j] = true;

		hasPath = HasPathCore(matrix, rows, i, cols, j - 1, str, pathLength, visited) ||
			HasPathCore(matrix, rows, i - 1, cols, j, str, pathLength, visited) ||
			HasPathCore(matrix, rows, i, cols, j + 1, str, pathLength, visited) ||
			HasPathCore(matrix, rows, i + 1, cols, j, str, pathLength, visited);
		if (!hasPath) {
			--pathLength;
			visited[i*cols + j] = false;
		}
	}
	return hasPath;
}
//������ʮ���������˵��˶���Χ�����ݷ�
int robotRoad(int threshold, int rows, int cols) {
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;
	
	bool *visited = new bool[rows*cols];
	/*for (int i = 0; i < rows*cols; ++i)
		visited[i] = false;*/
	memset(visited, 0, rows*cols);
	int count = robotRoadCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}
int robotRoadCore(int threshold, int rows, int cols, int i, int j, bool *visited) {
	int count = 0;
	if (check(threshold, rows, cols, i, j, visited)) {
		visited[i*cols + j] = true;
		count = 1 + robotRoadCore(threshold, rows, cols, i, j - 1, visited) +
			robotRoadCore(threshold, rows, cols, i - 1, j, visited) +
			robotRoadCore(threshold, rows, cols, i, j + 1, visited) +
			robotRoadCore(threshold, rows, cols, i + 1, j, visited);
	}
	return count;
}
bool check(int threshold, int rows, int cols, int i, int j, bool *visited) {
	if (rows>i&&cols>j&&i>=0&&j>=0&&(getDigitSum(i) + getDigitSum(j))<=threshold&&(!visited[i*cols+j])) {
		return true;
	}
	return false;
}
int getDigitSum(int i) {
	int sum = 0;
	while (i>0) {
		sum += (i % 10);
		i /= 10;
	}
	return sum;
}
//������ʮ�ģ�������
int maxProductAfterCutting1(int length) {
	//��̬�滮�ⷨ
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int *products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;//products[3]�ǰ�4�г�1��3���3�����ǵ�length=3�Ƿ���2
	int max = 0;
	for (int i = 4; i <= length; ++i) {
		max = 0;
		for (int j = 1; j <= i / 2; ++j) {			
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}
		products[i] = max;
	}
	max = products[length];
	delete[] products;
	return max;
}
double maxProductAfterCutting2(int length) {
	//̰���㷨���
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int timesOf3 = length / 3;
	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;
	int timesOf2 = (length - timesOf3 * 3) / 2;
	return pow(3, timesOf3)*pow(2, timesOf2);
}
//������ʮ�壺����������1�ĸ���
int numberOf1_1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n&flag)		//ÿ���ж�n�����λ�ǲ���1
			++count;
		flag = flag << 1;		//Ȼ��flag����1λ
		//n>>1;			//ÿ�ν�n����1λ�ǲ��׵ģ���nΪ���������ƺ���߲�1��һֱ��1���ͻᵼ����ѭ��
	}
	return count;
}
int numberOf1_2(int n) {//������
	int count = 0;
	while (n) {
		++count;
		n = n&(n - 1);//��һ��������ȥ1���ٺ�ԭ����������������õ��Ľ���൱�ڰ������Ķ����Ʊ�ʾ�����ұߵ�1���0
	}
	return count;
}
//�����Ŀ
bool isPowerOf2(int n) {//�ж�n�Ƿ���2����
	n = n&(n - 1);
	if (n == 0)
		return true;
	else
		return false;
}
int changeBit(int m, int n) {//�ı�m�Ķ����Ʊ�ʾ�еĶ���λ���ܵõ�n
	int h = m^n;
	int count = 0;
	while (h) {
		++count;
		h = h&(h - 1);
	}
	return count;
}
//������ʮ������ֵ�������η�
double power(double base, int exponent, bool &invalidInput) {
	if (fabs(base-0.0)<0.00001 && exponent < 0) {//����Ϸ��Լ��
		invalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)			//ָ��Ϊ��
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent2(base, absExponent);
	if (exponent < 0) {
		return 1.0 / result;
	}
	return result;
}
double PowerWithUnsignedExponent1(double base, unsigned int absExponent) {
	double result = 1.0;
	for (unsigned int i = 1; i <= absExponent; ++i) {
		result = result*base;
	}
	return result;
}
double PowerWithUnsignedExponent2(double base, unsigned int absExponent) {
	//���ݵĸ߼�����
	if (absExponent == 0)
		return 1;
	if (absExponent == 1)
		return base;
	double result = PowerWithUnsignedExponent2(base, absExponent >> 1);//�����൱�ڳ���2,Ч�ʸ���
	result *= result;
	if ((absExponent & 1) == 1) {//�ж�ָ������������ż���������������Ч�ʸ�
		result *= base;
	}
	return result;
}
//������ʮ�ߣ���ӡ��1������nλ������������
void Print1ToMaxOfNDigits_1(int n) {
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increment(number)) {
		PrintNumber(number);
	}
	delete[]number;
}
bool Increment(char* number) {
	// �ַ���number��ʾһ�����֣��� number������1
	// ������ӷ�������򷵻�true������Ϊfalse
	int nSum=0, nTakeover=0;
	bool isOverflow = false;
	size_t length = strlen(number);
	for (auto i = length - 1; i >= 0; --i) {
		nSum = number[i] - '0' + nTakeover;
		if (i == length - 1)
			++nSum;
		if (nSum >= 10) {
			if (i == 0)
				isOverflow = true;
			else {
				nSum -= 10;
				nTakeover = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}
void PrintNumber(char *number) {
	// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
	// ��ӡ��������֣������Կ�ͷ��0
	bool isFirst = true;
	size_t length = strlen(number);
	for (auto i = 0; i < length; ++i) {
		if (isFirst&&number[i] != '0') {//�ǵ�һ��������Ϊ0
			isFirst = false;
		}
		if (!isFirst)
			cout << number[i];
	}
	cout << '\t';
}
void Print1ToMaxOfNDigits_2(int n)
{	//���������õݹ飬n=3ʱ����ӡ1~999�൱�����3�����ֵ�ȫ����
	if (n <= 0)
		return;
	char *number = new char[n+1];
	number[n] = '\0';
	for (int i = 0; i < 10; ++i) {
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1) {
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}
//�������ʮһ��ʹ����λ��ż��ǰ�������ݽṹ����д��
//�������ʮ���������е�����k���ڵ������ݽṹ����д��
//�������ʮ�ģ���ת���������ݽṹ����д��
//������25���ϲ�������������������ݽṹ����д��
//������26�������ӽṹ
bool HasSubtree(BTNode *root1, BTNode *root2) {//����Ǵ�ĵݹ���
	bool result = false;
	if (root1&&root2) {
		if (abs(root1->data - root2->data) < 0.000001)
			result = DoesTree1HaveTree2(root1, root2);
		if(!result)
			result = DoesTree1HaveTree2(root1->lchild, root2);
		if (!result)
			result = DoesTree1HaveTree2(root1->rchild, root2);
	}
	return result;
}
bool DoesTree1HaveTree2(BTNode *root1, BTNode *root2) {//�����С�ĵݹ�
	if (!root2)
		return true;
	if (!root1)
		return false;
	if (!(abs(root1->data - root2->data) < 0.000001))
		return false;
	return DoesTree1HaveTree2(root1->lchild, root2->lchild) && DoesTree1HaveTree2(root1->lchild, root2->lchild);
}
//������27���������ľ��������ݽṹ����д��
//������28���ԳƵĶ�����
bool isSymmetry(BTNode *root) {
	return isSymmetry(root, root);
}
bool isSymmetry(BTNode *root1, BTNode *root2) {
	if (root1 == NULL&&root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;
	if (root1->data != root2->data)
		return false;
	return isSymmetry(root1->lchild, root2->rchild) && isSymmetry(root1->rchild, root2->lchild);

}
//������30������min������ջ��ͷ�ļ���
//������31��ջ��ѹ�롢��������
bool isPopOrder(const int *pPush, const int *pPop, int length) {
	//�������ֲ��ȣ��жϵ��������Ƿ���ȷ������ѹ������Ϊ{1��2��3��4��5},{4��5��3��2��1}����һ����ȷ�ĵ�������
	if (pPush&&pPop&&length > 0) {
		const int *pNextPush = pPush;//����ָ��ֱ�ָ����������
		const int *pNextPop = pPop;
		stack<int> stackData;
		while (pNextPop - pPop != length) {
			while (stackData.empty() || stackData.top() != *pNextPop) {
				if (pNextPush - pPush == length)
					break;
				stackData.push(*pNextPush);
				++pNextPush;
			}
			if (stackData.top() != *pNextPop)
				break;
			stackData.pop();
			++pNextPop;
		}
		if (stackData.empty() && pNextPop - pPop == length)
			return true;
	}
	return false;

}
//������32����α���
void LevelPrint(BTNode *root) {
	if (root) {
		deque<BTNode *> myQueue;
		myQueue.push_back(root);
		while (myQueue.size()) {
			BTNode *p = myQueue.front();
			myQueue.pop_front();
			cout << p->data << '\t';
			if(p->lchild)
				myQueue.push_back(p->lchild);
			if (p->rchild)
				myQueue.push_back(p->rchild);
		}
	}
	cout << endl;
}
//�����Ŀ�����д�ӡ������
void LevelPrint2(BTNode *root) {
	if (!root)
		return;
	BTNode *p;
	deque<BTNode *> myQueue;
	int nextLevel = 0;	//��ʾ��һ��Ľڵ���
	int toBePrinted = 1;	//��ʾ��ǰ���л�û�б���ӡ�Ľڵ���
	myQueue.push_back(root);
	while (!myQueue.empty()) {
		p = myQueue.front();
		myQueue.pop_front();
		cout << p->data << '\t';
		--toBePrinted;
		if (p->lchild) {
			myQueue.push_back(p->lchild);
			++nextLevel;
		}
		if (p->rchild) {
			myQueue.push_back(p->rchild);
			++nextLevel;
		}
		if (toBePrinted == 0) {
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;	//����һ���˾����¼������
		}		
	}
}
//֮���Դ�ӡ������
void LevelPrint3(BTNode *root) {
	if (!root)
		return;
	BTNode *p;
	stack<BTNode *> myStack[2];	//��������ջ
	int current = 0, next = 1;	//current��next�ֱ����ǰջ����һ��ջ
	myStack[current].push(root);
	while (!myStack[0].empty() || !myStack[1].empty()) {
		p = myStack[current].top();
		cout << p->data << '\t';
		myStack[current].pop();
		if (current == 0) {
			if (p->lchild)
				myStack[next].push(p->lchild);
			if (p->rchild)
				myStack[next].push(p->rchild);
		}
		if (current == 1) {
			if (p->rchild)
				myStack[next].push(p->rchild);
			if (p->lchild)
				myStack[next].push(p->lchild);
		}
		if (myStack[current].empty()) {
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}
//������33���жϸ����������ǲ���һ�Ŷ����������ĺ�������
bool VerifySequenceOfBST(int Sequence[], int length) {
	if (length <= 0)
		return false;
	int root = Sequence[length - 1];		//���Ǻ��������������һ���ڵ��Ǹ��ڵ�
	int i = 0;
	for (; i < length - 1; ++i) {	//�ҵ���һ������root�ĵ㣬ǰ�漴��������
		if (Sequence[i] > root)
			break;
	}
	int j = i;
	for (; j < length - 1; ++j) {	//������������С��root�ģ�ֱ�ӷ���false����Ϊ��һ�ö���������
		if (Sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0) {			//����ж���ȷ�����ȴ���0
		left = VerifySequenceOfBST(Sequence, i);
	}
	bool right = true;
	if (i < length - 1) {	//����ж�Ҳ��ȷ�����ȴ���0
		right = VerifySequenceOfBST(Sequence + i, length - i - 1);
	}
	return left&&right;
}
//������34���������к�Ϊĳһֵ��·�������ݽṹ����д��
//������39�������г��ִ�������һ�������
int MoreThanHalfNum(int *num, int length) {
	//��һ��ʹ�ÿ���
	if (num == NULL || length <= 0)
		return 0;
	int middle = length >> 1;
	int start = 0, end = length - 1;
	int index = Partition(num, start, end);
	while (middle != index) {
		if (middle > index) {
			start = index + 1;
			index = Partition(num, start, end);
		}
		else {
			end = index - 1;
			index = Partition(num, start, end);
		}
	}
	int result = num[middle];
	if (!CheckMoreThanHalf(num, length, result))
		return 0;
	return result;
}
int Partition(int *num, int start,int end) {
	int temp = num[start];
	while (start < end) {
		while (start < end&&num[end] >= temp) --end;
		num[start] = num[end];
		while (start < end&&num[start] <= temp) ++start;
		num[end] = num[start];
	}
	num[start] = temp;
	return start;
}
bool CheckMoreThanHalf(int *num, int length, int number) {
	//�鿴��������ǲ��ǳ�������һ����
	int times = 0;
	for (int i = 0; i < length; ++i) {
		if (num[i] == number)
			++times;
	}
	if (times * 2 <= length) {
		return false;
	}
	return true;
}
int MoreThanHalfNum2(int *num, int length) {
	//������ÿ�α�������������������O(n)��ʱ��
	if (num == NULL || length <= 0)
		return 0;
	int result = num[0];
	int times = 1;
	for (int i = 1; i < length; ++i) {
		if (times == 0) {
			result = num[i];
			times = 1;
		}
		if (result == num[i])
			++times;
		else
			--times;
	}
	if (!CheckMoreThanHalf(num, length, result))
		return 0;
	return result;
}
//������40����С��k����
void GetLeastNumber(int *input, int n, int *output, int k) {
	//����������С��k����,��һ���ÿ��ţ�O(n)
	if (input == NULL || output == NULL ||  n <= 0 || k <= 0 || k > n)
		return;
	int start = 0, end = n - 1;
	int index = Partition(input, start, end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = Partition(input, start, end);
		}
		else {
			start = index + 1;
			index = Partition(input, start, end);
		}
	}
	for (int i = 0; i < k; ++i) {
		output[i] = input[i];
	}
}
void GetLeastNumber2(const vector<int>& data,intSet& leastNumbers,int k) {
	leastNumbers.clear();
	if (k < 1 || data.size() < k)
		return;
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter) {
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else {
			setIterator iterGreatest = leastNumbers.begin();
			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}
//������41���������е���λ����д����ͷ�ļ���
//������42�����������������
int FindGreatestSumOfSubArray(int *data, int length){
	if (data == nullptr || length < 0) {
		cout << "������Ч" << endl;
		return 0;
	}
	int CurrentSum = 0;
	int GreatestSum = -9999;			//�������
	for (int i = 0; i < length; ++i) {
		if (CurrentSum <= 0)
			CurrentSum = data[i];
		else
			CurrentSum += data[i];
		if (CurrentSum > GreatestSum)
			GreatestSum = CurrentSum;
	}
	return GreatestSum;
}
//������43��1~n������1���ֵĴ���
int NumberOf1Between1AndN(unsigned int n) {//�򵥽ⷨ
	int number = 0;
	for (unsigned int i = 1; i <= n; ++i) {
		number += NumberOf1(i);
	}
	return number;
}
int NumberOf1(unsigned int i) {
	int number = 0;
	while (i) {
		if (i % 10 == 1)
			++number;
		i /= 10;
	}
	return number;
}
//������44������������ĳһλ������
int digitAtIndex(int index) {//������01234567891011...�ĸ�ʽ���л���һ���ַ������У��������nλ��Ӧ������
	if (index < 1)
		return -1;
	int digit = 1;
	while (1) {
		int number = countOfIntegers(digit);
		if (index < digit*number)
			return digitAtIndex(index, digit);
		index -= digit*number;
		++digit;
	}
}
int countOfIntegers(int digit) {//��������õ�mλ�������ж��ٸ�
	if (digit == 1)
		return 10;
	int count = static_cast<int>(pow(10, digit - 1));	//��Ϊpow���ص���double���͵ģ�����Ҫת��
	return 9 * count;
}
int digitAtIndex(int index, int digit) {
	int number = beginNumber(digit) + index / digit;
	int indexFromRight = digit - index % digit;
	for (int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}
int beginNumber(int digit) {	//mλ���ĵ�һ������
	if (digit == 1)
		return 10;
	return static_cast<int>(pow(10, digit - 1));
}
int digitAtIndex2(int n) {
	//��������0��ʼö��,��ÿһλ��λ�����ۼ�����
	int sum = 0;
	int current = 0;
	while (1) {
		sum += digit2(current);
		if (sum <= n) {
			++current;
		}
		else {
			int diff = n - (sum - digit2(current))+1;		//diff��ʾ������ֵĵڼ�λ
			int indexFromRight = digit2(current) - diff + 1;	//��ʾ���ɿ�ʼ���ڼ�λ
			for (int i = 1; i < indexFromRight; ++i) {
				current /= 10;
			}
			return current%10;
		}
	}
}
int digit2(int current) {
	if (current == 0)
		return 1;
	else {
		int count = 0;
		while (current) {
			++count;
			current /= 10;
		}
		return count;
	}
}
//������47����������ֵ
int getMaxValue_solution1(const int* values, int rows, int cols) {
	if (values == nullptr || rows < 0 || cols < 0)
		return 0;
	int **maxValues = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		maxValues[i] = new int[cols];
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int up = 0;
			int left = 0;
			if (i > 0)
				up = maxValues[i - 1][j];
			if (j > 0)
				left = maxValues[i][j - 1];
			maxValues[i][j] = max(up, left) + values[i*cols + j];
		}
	}
	int maxValue = maxValues[rows - 1][cols - 1];
	for (int i = 0; i < rows; ++i)
		delete[] maxValues[i];
	delete[] maxValues;
	return maxValue;
}
int getMaxValue_solution2(const int* values, int rows, int cols) {
	if (values == nullptr || rows < 0 || cols < 0)
		return 0;
	int *maxValues = new int[cols];
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int up = 0;
			int left = 0;
			if (i > 0)
				up = maxValues[j];
			if (j > 0)
				left = maxValues[j - 1];
			maxValues[j] = max(up, left) + values[i*cols + j];
		}
	}
	int maxValue = maxValues[cols - 1];
	delete[] maxValues;
	return maxValue;
}
//������49������:ֻ�ܱ�2��3��5��������
int GetUglyNumber_Solution1(int index) {
	//1�ǵ�һ���������󰴴�С�����˳��ĵ�1500������
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index) {
		++number;
		if (isUglyNumber(number))
			++uglyFound;
	}
	return number;
}
bool isUglyNumber(int number) {
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
int GetUglyNumber_Solution2(int index) {
	if (index <= 0)
		return 0;
	int *UglyNumbers = new int[index];
	UglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	int *Multiply2 = UglyNumbers;
	int *Multiply3 = UglyNumbers;
	int *Multiply5 = UglyNumbers;
	while (nextUglyIndex < index) {
		int min = Min(*Multiply2 * 2, *Multiply3 * 3, *Multiply5 * 5);
		UglyNumbers[nextUglyIndex] = min;
		while (*Multiply2 * 2 <= UglyNumbers[nextUglyIndex])
			++Multiply2;
		while (*Multiply3 * 3 <= UglyNumbers[nextUglyIndex])
			++Multiply3;
		while (*Multiply5 * 5 <= UglyNumbers[nextUglyIndex])
			++Multiply5;
		++nextUglyIndex;
	}
	int ugly = UglyNumbers[index - 1];
	delete[] UglyNumbers;
	return ugly;
}
int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;
	return (min < number3) ? min : number3;
}
//������50����һ��ֻ����һ�ε��ַ�
char FirstNotRepeatingChar(char* pString) {
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (auto i = 0; i < tableSize; ++i)
		hashTable[i] = 0;
	char *pHashKey = pString;
	while (*pHashKey != '\0') {
		hashTable[*(pHashKey++)]++;
	}
	pHashKey = pString;
	while (*pHashKey != '\0') {
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';
}
//�����Ŀ�����������ַ������ӵ�һ���ַ�����ɾ���ڵڶ����ַ����г��ֵ������ַ�
void DeleteFirstString(char string1[], char string2[]) {
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (auto i = 0; i < 256; ++i)
		hashTable[i] = 0;
	char *hashKey = string2;
	while (*hashKey != '\0')
		hashTable[*(hashKey++)]++;
	char *p = string1,*q=string1;
	for (; *p != '\0'; q++) {
		if (hashTable[*q] != 1)
			*p++=*q;
	}
	*p='\0';
}
void delete_char(char str[], char c)
{
	//ɾ���ַ����е�ָ���ַ�
	char *p = str, *q = str;
	for (; *q != '\0'; q++)
	{
		if (*q != c)
			*p++ = *q;
	}
	*p = '\0';
}
void Delete_Repeat(char str[]) {
	//ɾ���ַ������ظ����ַ�
	bool hashTable[256] = { false };
	char *p = str,*q=str;
	while (*q != '\0') {
		if (hashTable[*q] == false) {
			hashTable[*q] = true;
			*p++ = *q;
		}
		q++;
	}
	*p = '\0';
}
bool Anagram(char str1[], char str2[]) {
	//�ж������ַ����Ƿ�Ϊ��λ��
	unsigned int hashTable[256] = {0};
	char *p = str1;
	while (*p != '\0')
		hashTable[*(p++)]++;
	char *q = str2;
	while (*q != '\0') {
		hashTable[*(q++)]--;
	}
	for (auto i = 0; i < 256; ++i) {
		if (hashTable[i] != 0)
			return false;
	}
	return true;
}
//������51�������е������
//������52����������ĵ�һ�������ڵ������ݽṹ����д��
//������53�������������в�������
int GetNumberOfK(int *data, int length, int k) {
	//ͳ��һ�����������������г��ֵĴ�������{1��2��3��3��3��3��4��5}������3��3������4�Σ�O(logn)��ʱ�临�Ӷ�
	int number = 0;
	int first = GetFirstK(data, k, length, 0, length - 1);
	int last = GetLastK(data, k, length, 0, length - 1);
	if(first>-1&&last>-1)
		number = last - first + 1;
	return number;
}
int GetFirstK(int *data, int k, int length, int start, int end) {
	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k) {
		if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)//���ǰһ��ֵ����k,˵��middleIndex�ǵ�һ��k
			return middleIndex;
		else
			end = middleIndex - 1;
	}
	else if (middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;
	return GetFirstK(data, k, length, start, end);
}
int GetLastK(int *data, int k, int length, int start, int end) {
	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k) {
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)//ͬ��
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if (middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;
	return GetLastK(data, k, length, start, end);
}
//������53��Ŀ����0~n-1��ȱʧ������
int GetMissingNumber(int *data, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int middle = (left + right) >> 1;
		if (data[middle] != middle) {
			if (middle == 0 || data[middle - 1] == middle - 1)//��һ��������������ֵ
				return middle;
			else
				right = middle - 1;
		}
		else
			left = middle + 1;
	}
	if (left == length)
		return length;
	return -1;
}
//������53��Ŀ��������������������ֵ���±���ȵ�Ԫ��
int GetNumberSameAsIndex(int *data, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (data[middle] == middle)
			return middle;
		else if (data[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}
//������56��Ŀһ��������ֻ����һ�ε���������
void FindNumberAppearOnce(int *data, int length, int &num1, int &num2) {
	//�����г���2�����֣��������ֶ����������Σ���ô������κ�͵�0
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i) {
		resultExclusiveOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
	for (int i = 0; i < length; ++i) {
		if (IsBit1(data[i], indexOf1))
			num1 ^= data[i];
		else
			num2 ^= data[i];
	}
}
unsigned int FindFirstBitIs1(int num) {
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
		num = num >> 1;
		indexBit++;
	}
	return indexBit;
}
bool IsBit1(int num, unsigned int indexOf1) {
	num = num >> indexOf1;
	return (num & 1);
}
//������55��Ŀһ���������
int TreeDepth(BTNode *root) {
	if (root == nullptr)
		return 0;
	int left = TreeDepth(root->lchild);
	int right = TreeDepth(root->rchild);
	return (left > right) ? (1 + left) : (1 + right);
}
//������54�������������ĵ�K���ڵ�
BTNode *KthNode(BTNode *root,int k) {
	if (root == nullptr)
		return nullptr;
	return KthNodeCore(root, k);
}
BTNode *KthNodeCore(BTNode *root, int &k) {
	BTNode *target = nullptr;
	if (root->lchild != nullptr)
		target=KthNodeCore(root->lchild, k);
	if (target == nullptr) {
		if (k == 1)
			return root;
		--k;
	}
	if(target==nullptr&&root->rchild != nullptr)
		target = KthNodeCore(root->rchild, k);
	return target;
}
//������55��Ŀ�����ж��Ƿ���ƽ�������
bool isBalanced1(BTNode *root) {
	if (root == nullptr)
		return true;
	int left = TreeDepth(root->lchild);
	int right = TreeDepth(root->rchild);
	int diff = left - right;
	if (diff < -1 || diff > 1) {
		return false;
	}
	return isBalanced1(root->lchild) && isBalanced1(root->rchild);
}
bool isBalanced2(BTNode *root) {
	int depth = 0;
	return isBalanced2(root, &depth);
}
bool isBalanced2(BTNode *root, int  *depth) {
	//�ڱ���ĳ�ڵ�����ҽڵ�����ǿ��Ը����������ҽڵ������ж����ǲ���ƽ��ģ����õ���ǰ�ڵ����ȡ��������������ĸ��ڵ�ʱ��
	//Ҳ���ж��������������ǲ���ƽ�����
	if (root == nullptr) {
		*depth = 0;
		return true;
	}
	int left, right;
	if (isBalanced2(root->lchild, &left) && isBalanced2(root->rchild, &right)) {
		int diff = left - right;
		if (diff <= 1 && diff >= -1) {
			*depth = 1 + ((left > right) ? left : right);
			return true;
		}
	}
	return false;
}
//������56��Ŀ����������ֻ��һ��������1�Σ�����������3��
int FindNumberAppearOnce(int *data, int length) {
	int bitSum[32] = { 0 };
	for (int i = 0; i < length; ++i) {
		int bitMask = 1;
		for (int j = 31; j >= 0; --j) {
			int bit = (data[i] & bitMask);
			if (bit != 0)
				bitSum[j] += 1;
			bitMask = bitMask << 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; ++i) {
		result = result << 1;
		result += bitSum[i] % 3;
	}
	return result;
}
//������57��Ŀһ����Ϊs������
bool SumIsS(int *data, int length, int s, int *num1, int *num2) {
	//�ڵ����������ҵ���Ϊs��������������ж�ԣ�ֻ���һ��
	int left = 0;
	int right = length - 1;
	bool found = false;
	while (left < right) {
		if ((data[left] + data[right]) == s) {
			*num1 = data[left];
			*num2 = data[right];
			found = true;
			break;
		}
		else if ((data[left] + data[right]) < s)
			++left;
		else
			--right;
	}
	return found;
}
//������57��Ŀ������Ϊs��������������
void ContinuousSequenceIsS(int sum) {
	if (sum < 3)
		return;
	int small = 1;
	int big = 2;
	int middle = (sum + 1) / 2;
	int curSum = small + big;
	while (small < middle) {
		if (curSum == sum)
			printSequence(small, big);
		while (curSum > sum) {
			curSum -= small;
			small++;
			if (curSum == sum)
				printSequence(small, big);
		}
		big++;
		curSum += big;
	}
}
void printSequence(int small, int big) {
	for (int i = small; i <= big; ++i) {
		cout << i << '\t';
	}
	cout << endl;
}
//������58��Ŀһ����ת�ַ���
void Reverse(char *begin, char *end) {
	if (begin == nullptr || end == nullptr)
		return;
	while (begin < end) {
		char temp = *begin;
		*begin = *end;
		*end = temp;

		begin++;
		end--;
	}
}
void ReverseSentence(char *data) {
	//���롰I am a student.���������student. a am I��
	if (data == nullptr)
		return;
	char *begin = data, *end = data;
	while (*end != '\0')
		++end;
	end--;
	Reverse(begin, end);
	begin = end = data;
	while (*begin != '\0') {
		if (*begin == ' ') {//�����������������ո�����
			++begin;
			++end;
		}
		else if (*end == ' ' || *end == '\0') {
			Reverse(begin, --end);
			begin = ++end;
		}
		else
			++end;
	}
}
//������58��Ŀ������ת�ַ���
char* LeftRotateString(char *str,int n) {
	//���롰abcdefg���������cdefgab��
	if (str) {
		int length = static_cast<int>(strlen(str));
		if (length > 0 && n > 0 && n < length) {
			char *firstStart = str;
			char *firstEnd = str + n - 1;
			char *secondStart = str + n;
			char *secondEnd = str + length - 1;

			Reverse(firstStart, firstEnd);
			Reverse(secondStart, secondEnd);
			Reverse(firstStart, secondEnd);
		}
	}
	return str;
}
//������61���˿��е�˳��
bool isContinue(int *data, int length) {
	//�ж�������n�����Ƿ���˳�ӣ�0�ɴ���������
	int numberZero = 0;//0�ĸ���
	int numberGap = 0;//�����С
	bucketSort(data, length);
	for (int i = 0; i < length; ++i) {
		if (data[i] == 0)
			++numberZero;
	}
	int small = 0;
	int big = small + 1;
	for (int i = 0; i < length; ++i) {
		if (data[small] == data[big])
			return false;
		numberGap = data[big] - data[small] - 1;
		small = big;
		++big;
	}
	return (numberZero >= numberGap) ? true : false;
}
void bucketSort(int *data,int length) {
	int bucket[14] = { 0 };
	for (int i = 0; i < length; ++i) {
		bucket[data[i]]++;
	}
	int index = 0;
	for (int i = 0; i < 14; ++i) {
		while (bucket[i]) {
			data[index++] = i;
			--bucket[i];
		}
	}
}
//������62��ԲȦ�����ʣ�µ�����
int LastRemaining(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1)
		return -1;
	list<int> numbers;
	for (auto i = 0; i < n; ++i)
		numbers.push_back(i);
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1) {
		for (unsigned int i = 1; i < m; ++i) {
			++current;
			if (current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		--current;
		numbers.erase(current);
		current = next;
	}
	return *current;
}
//������63����Ʊ���������
int MaxDiff(const int *data, unsigned int length) {
	if (data == nullptr || length < 2)
		return 0;
	int min = data[0];
	int maxDiff = data[1] - min;
	for (unsigned int i = 2; i < length; ++i) {
		if (data[i - 1] < min)
			min = data[i - 1];
		int currDiff = data[i] - min;
		if (currDiff > maxDiff)
			maxDiff = currDiff;
	}
	return maxDiff;
}
//������65�����üӼ��˳��Ž��������������
int SumWithBit(int num1, int num2) {
	int sum = 0;
	int carry = 0;
	do {
		sum = num1^num2;//ֻ�Ӳ���λ��
		carry = (num1&num2) << 1;//��λ
		num1 = sum;
		num2 = carry;
	} while (carry != 0);
	return sum;
}
//������66�������˻�����
void mutiply(const vector<double>& input, vector<double>& output) {
	//��Ŀ������һ������A[0, 1, ��, n - 1]���빹��һ������B[0, 1, ��, n - 1]����
	//��B�е�Ԫ��B[i] = A[0]��A[1]���� ��A[i - 1]��A[i + 1]������A[n - 1]������ʹ�ó�����
	size_t length1 = input.size();
	size_t length2 = output.size();
	if (length1 == length2&&length2 > 1) {
		output[0] = 1;	//�൱��c[0]
		for (int i = 1; i < length1; ++i) {
			output[i] = output[i - 1] * input[i - 1];
		}
		double temp = 1;//�൱��d[n-1]
		for (size_t i = length1 - 2; i >= 0; --i) {
			temp *= input[i + 1];
			output[i] *= temp;
		}
	}
}
// ������67�����ַ���ת��������
// ��Ŀ������дһ������StrToInt��ʵ�ְ��ַ���ת��������������ܡ���Ȼ����
// ��ʹ��atoi�����������ƵĿ⺯����
enum Status { Valid = 0, Invalid };
int g_Status = Valid;
long long StrToIntCore(const char *str, bool minus) {
	long long num = 0;
	while (*str != '\0') {
		if ((*str >= '0'&&*str <= '9')) {
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*str - '0');
			if ((!minus&&num > 0x7FFFFFFF) || (minus&&num < (signed int)0x80000000)) {
				num = 0;
				break;
			}
			++str;
		}
		else{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
		g_Status = Valid;
	return num;
}
int StrToInt(const char* str) {
	g_Status = Invalid;
	long long num = 0;
	if (str != nullptr || *str != '\0') {
		bool minus = false;
		if (*str == '+')
			++str;
		if (*str == '-') {
			minus = true;
			++str;
		}
		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}

// ������19��������ʽƥ��
// ��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'
// ��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ�,��patternȥƥ��str��'aaaaabb'��'a*bb'ƥ�䣬
//'*'��ʾ��ǰ����ַ����Գ����������ֵstr������ַ��ظ����
bool match(const char* str, const char* pattern) {
	if (str == nullptr || pattern == nullptr)
		return false;
	return matchCore(str, pattern);
}
bool matchCore(const char* str, const char* pattern) {
	if (*str == '\0'&&*pattern == '\0')
		return true;
	if (*str != '\0'&&*pattern == '\0')//str���У�ģʽû�ˣ��϶���ƥ�䣻Ҫ��strû�ˣ�ģʽ�����ǿ���ƥ���
		return false;
	if (*(pattern + 1) == '*') {
		if ((*pattern == *str) || (*pattern == '.'&&*str != '\0')) {
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
		}
		else
			return matchCore(str, pattern + 2);
	}
	if ((*str == *pattern) || (*pattern == '.'&&*str != '\0')) {
		return matchCore(str + 1, pattern + 1);
	}
	return false;
}

//�������ʮ����ʾ��ֵ���ַ���
bool isNumberic(const char *str) {
	if (str == nullptr)
		return false;
	bool numberic = scanInteger(&str);
	if (*str == '.') {
		++str;
		numberic = scanUnsignedInteger(&str) || numberic;
	}
	if (*str == 'E' || *str == 'e') {
		++str;
		numberic = numberic&&scanInteger(&str);
	}
	return numberic && (*str == '\0');
}
bool scanInteger(const char **str) {
	if (**str == '+' || **str == '-')
		++(*str);
	return scanUnsignedInteger(str);
}
bool scanUnsignedInteger(const char **str) {
	const char *before = *str;
	while (**str != '\0'&&**str >= '0' && **str <= '9')
		++(*str);
	return *str > before;
}