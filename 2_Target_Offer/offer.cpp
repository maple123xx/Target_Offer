#include"offer.h"

//面试题3
//1.找出数组中任意一个重复的数字
bool Duplicate(int *A, int length, int *duplicate) {
	//法一：O(n)的时间，O(1)的空间
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
	//法二：桶方法，O(n)的时间内，O(n)的空间
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
//2.不修改数组，找出数组任意一个重复的数字
int Duplicate2(const int *A,int length) {//申明为const是防止修改
	//长度为n+1的数组，元素为1~n的数字
	//O(nlogn)的时间，O(1)的空间
	//该方法不能找出所有重复的数字
	int start = 1;
	int end = length - 1;
	while (end >= start) {
		//int mid = ((end - start) >> 1) + start;//>>1就是除以2，这种求mid的方式适用于从1开始的数组，从0开始就不能用了
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
//面试题4：在二维数组里找指定的数(每一行从左到右递增，从上到下递增)
bool Matrix_Find(int *A, int rows,int cols,int obj) {
	int row = 0,col=cols-1;
	bool found = false;
	while (row <= rows - 1 && col >= 0) {
		if (A[row*cols + col] == obj) {//从右上角的数开始比较
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
//面试题5：替换空格
void ReplaceBlank(char str[]) {
	//将空格替换为%20，由于增加字符，要不覆盖后面的字符，所以从后往前复制
	//O(n)的时间，O(1)的空间
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
	//面试题5的相关题目，A和B都是升序数组，A足够大，把A,B合并，且合并后仍是升序
	//从后往前复制，就可以减少移动次数
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
//面试题6：从头到尾打印链表，在数据结构里面已经写过了
//面试题7：重建二叉树，在数据结构里面已经写过了
//面试题8：二叉树的下一个节点
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
	//求某个节点的中序遍历的下一个节点
	if (!pNode)
		return NULL;
	BTNode *pNext = NULL;
	if (pNode->rchild) {	//如果该节点有右孩子，则下一个节点为右子树的最左下节点
		BTNode *pRight = pNode->rchild;
		while (pRight->lchild){
			pRight = pRight->lchild;
		}
		pNext = pRight;
	}
	else if (pNode->parent) {	//如果它没有右孩子
		BTNode *pCurrent = pNode;
		BTNode *pParent = pNode->parent;
		while (pParent&&pParent->rchild == pCurrent) {//若它是它父节点的左孩子，则下一个节点就是它的父节点
			pCurrent = pParent;						  //否则一直向上遍历，直到当前是它父节点的左孩子
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
//面试题9：用两个栈实现队列，写在头文件中了
//面试题10：斐波那契数列
long long Fibonacci(unsigned int n) {
	/*if (n == 0)	//递归：效率低
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);*/
	if (n == 0)		//非递归
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
//面试题十一：旋转数组的最小数字
int Rotate_Min(int *A, int length) {//[3,4,5,1,2]
	int low = 0, high = length - 1;
	int mid = low;	//若数组递增，循环一次也进不去，直接返回最小值A[low],所以把mid初始化为low
	while (A[low] >= A[high]) {
		if (high - low == 1) {
			mid = high;
			break;
		}
		mid = (low + high) / 2;
		if (A[low] == A[mid] && A[high] == A[mid]) {//若三者相等，则只能顺序查找，如[1,0,1,1,1]或[1,1,1,0,1]
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
//面试题十二：矩阵中的路径：回溯法
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
	if (str[pathLength] == '\0')//递归终止条件
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
//面试题十三：机器人的运动范围：回溯法
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
//面试题十四：剪绳子
int maxProductAfterCutting1(int length) {
	//动态规划解法
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
	products[3] = 3;//products[3]是把4切成1和3后的3，不是当length=3是返回2
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
	//贪心算法求解
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
//面试题十五：二进制数的1的个数
int numberOf1_1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n&flag)		//每次判断n的最低位是不是1
			++count;
		flag = flag << 1;		//然后将flag左移1位
		//n>>1;			//每次将n右移1位是不妥的，若n为负数，右移后左边补1，一直补1，就会导致死循环
	}
	return count;
}
int numberOf1_2(int n) {//方法二
	int count = 0;
	while (n) {
		++count;
		n = n&(n - 1);//把一个整数减去1后再和原来的数做与操作，得到的结果相当于把整数的二进制表示中最右边的1变成0
	}
	return count;
}
//相关题目
bool isPowerOf2(int n) {//判断n是否是2的幂
	n = n&(n - 1);
	if (n == 0)
		return true;
	else
		return false;
}
int changeBit(int m, int n) {//改变m的二进制表示中的多少位才能得到n
	int h = m^n;
	int count = 0;
	while (h) {
		++count;
		h = h&(h - 1);
	}
	return count;
}
//面试题十六：数值的整数次方
double power(double base, int exponent, bool &invalidInput) {
	if (fabs(base-0.0)<0.00001 && exponent < 0) {//输入合法性检查
		invalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)			//指数为负
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
	//求幂的高级方法
	if (absExponent == 0)
		return 1;
	if (absExponent == 1)
		return base;
	double result = PowerWithUnsignedExponent2(base, absExponent >> 1);//右移相当于除以2,效率更高
	result *= result;
	if ((absExponent & 1) == 1) {//判断指数是奇数还是偶数，与运算比求余效率高
		result *= base;
	}
	return result;
}
//面试题十七：打印从1到最大的n位数，大数问题
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
	// 字符串number表示一个数字，在 number上增加1
	// 如果做加法溢出，则返回true；否则为false
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
	// 字符串number表示一个数字，数字有若干个0开头
	// 打印出这个数字，并忽略开头的0
	bool isFirst = true;
	size_t length = strlen(number);
	for (auto i = 0; i < length; ++i) {
		if (isFirst&&number[i] != '0') {//是第一个数字且为0
			isFirst = false;
		}
		if (!isFirst)
			cout << number[i];
	}
	cout << '\t';
}
void Print1ToMaxOfNDigits_2(int n)
{	//方法二：用递归，n=3时，打印1~999相当于输出3个数字的全排列
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
//面试题二十一：使奇数位于偶数前面在数据结构里面写过
//面试题二十二：链表中倒数第k个节点在数据结构里面写过
//面试题二十四：反转链表在数据结构里面写过
//面试题25：合并两个排序的链表在数据结构里面写过
//面试题26：树的子结构
bool HasSubtree(BTNode *root1, BTNode *root2) {//这个是大的递归你
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
bool DoesTree1HaveTree2(BTNode *root1, BTNode *root2) {//这个是小的递归
	if (!root2)
		return true;
	if (!root1)
		return false;
	if (!(abs(root1->data - root2->data) < 0.000001))
		return false;
	return DoesTree1HaveTree2(root1->lchild, root2->lchild) && DoesTree1HaveTree2(root1->lchild, root2->lchild);
}
//面试题27：二叉树的镜像在数据结构里面写过
//面试题28：对称的二叉树
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
//面试题30：包含min函数的栈在头文件中
//面试题31：栈的压入、弹出序列
bool isPopOrder(const int *pPush, const int *pPop, int length) {
	//所有数字不等，判断弹出序列是否正确，比如压入序列为{1，2，3，4，5},{4，5，3，2，1}就是一个正确的弹出序列
	if (pPush&&pPop&&length > 0) {
		const int *pNextPush = pPush;//两个指针分别指向两个序列
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
//面试题32：层次遍历
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
//相关题目：分行打印二叉树
void LevelPrint2(BTNode *root) {
	if (!root)
		return;
	BTNode *p;
	deque<BTNode *> myQueue;
	int nextLevel = 0;	//表示下一层的节点数
	int toBePrinted = 1;	//表示当前层中还没有被打印的节点数
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
			nextLevel = 0;	//到下一层了就重新计算个数
		}		
	}
}
//之字性打印二叉树
void LevelPrint3(BTNode *root) {
	if (!root)
		return;
	BTNode *p;
	stack<BTNode *> myStack[2];	//定义两个栈
	int current = 0, next = 1;	//current和next分别代表当前栈和另一个栈
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
//面试题33：判断给定的序列是不是一颗二叉排序树的后续遍历
bool VerifySequenceOfBST(int Sequence[], int length) {
	if (length <= 0)
		return false;
	int root = Sequence[length - 1];		//若是后续遍历，则最后一个节点是根节点
	int i = 0;
	for (; i < length - 1; ++i) {	//找到第一个大于root的点，前面即是左子树
		if (Sequence[i] > root)
			break;
	}
	int j = i;
	for (; j < length - 1; ++j) {	//若右子树中有小于root的，直接返回false，因为是一棵二叉排序树
		if (Sequence[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0) {			//这个判断是确保长度大于0
		left = VerifySequenceOfBST(Sequence, i);
	}
	bool right = true;
	if (i < length - 1) {	//这个判断也是确保长度大于0
		right = VerifySequenceOfBST(Sequence + i, length - i - 1);
	}
	return left&&right;
}
//面试题34：二叉树中和为某一值得路径在数据结构里面写过
//面试题39：数组中出现次数超过一半的数字
int MoreThanHalfNum(int *num, int length) {
	//法一：使用快排
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
	//查看这个数字是不是超过数组一半了
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
	//法二：每次遍历保存次数这个变量，O(n)的时间
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
//面试题40：最小的k个数
void GetLeastNumber(int *input, int n, int *output, int k) {
	//输出数组的最小的k个数,法一：用快排，O(n)
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
//面试题41：数据流中的中位数，写在了头文件中
//面试题42：连续子数组的最大和
int FindGreatestSumOfSubArray(int *data, int length){
	if (data == nullptr || length < 0) {
		cout << "输入无效" << endl;
		return 0;
	}
	int CurrentSum = 0;
	int GreatestSum = -9999;			//子数组和
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
//面试题43：1~n整数中1出现的次数
int NumberOf1Between1AndN(unsigned int n) {//简单解法
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
//面试题44：数字序列中某一位的数字
int digitAtIndex(int index) {//数字以01234567891011...的格式序列化到一个字符序列中，求任意第n位对应的数字
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
int countOfIntegers(int digit) {//这个函数得到m位的数字有多少个
	if (digit == 1)
		return 10;
	int count = static_cast<int>(pow(10, digit - 1));	//因为pow返回的是double类型的，所以要转型
	return 9 * count;
}
int digitAtIndex(int index, int digit) {
	int number = beginNumber(digit) + index / digit;
	int indexFromRight = digit - index % digit;
	for (int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}
int beginNumber(int digit) {	//m位数的第一个数字
	if (digit == 1)
		return 10;
	return static_cast<int>(pow(10, digit - 1));
}
int digitAtIndex2(int n) {
	//法二：从0开始枚举,把每一位的位数都累加起来
	int sum = 0;
	int current = 0;
	while (1) {
		sum += digit2(current);
		if (sum <= n) {
			++current;
		}
		else {
			int diff = n - (sum - digit2(current))+1;		//diff表示这个数字的第几位
			int indexFromRight = digit2(current) - diff + 1;	//表示从由开始数第几位
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
//面试题47：礼物的最大值
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
//面试题49：丑数:只能被2，3，5整除的数
int GetUglyNumber_Solution1(int index) {
	//1是第一个丑数，求按从小到大的顺序的第1500个丑数
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
//面试题50：第一次只出现一次的字符
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
//相关题目：输入两个字符串，从第一个字符串中删除在第二个字符串中出现的所有字符
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
	//删除字符串中的指定字符
	char *p = str, *q = str;
	for (; *q != '\0'; q++)
	{
		if (*q != c)
			*p++ = *q;
	}
	*p = '\0';
}
void Delete_Repeat(char str[]) {
	//删除字符串中重复的字符
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
	//判断两个字符串是否为变位词
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
//面试题51：数组中的逆序对
//面试题52：两个链表的第一个公共节点在数据结构里面写过
//面试题53：在排序数组中查找数字
int GetNumberOfK(int *data, int length, int k) {
	//统计一个数字在排序数组中出现的次数，如{1，2，3，3，3，3，4，5}和数字3，3出现了4次，O(logn)的时间复杂度
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
		if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)//如果前一个值不是k,说明middleIndex是第一个k
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
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)//同理
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
//面试题53题目二：0~n-1中缺失的数字
int GetMissingNumber(int *data, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int middle = (left + right) >> 1;
		if (data[middle] != middle) {
			if (middle == 0 || data[middle - 1] == middle - 1)//第一个不等于索引的值
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
//面试题53题目三：单调递增数组中数值和下标相等的元素
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
//面试题56题目一：数组中只出现一次的两个数字
void FindNumberAppearOnce(int *data, int length, int &num1, int &num2) {
	//数组中除了2个数字，其他数字都出现了两次，那么异或两次后就得0
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
//面试题55题目一：树的深度
int TreeDepth(BTNode *root) {
	if (root == nullptr)
		return 0;
	int left = TreeDepth(root->lchild);
	int right = TreeDepth(root->rchild);
	return (left > right) ? (1 + left) : (1 + right);
}
//面试题54：二叉搜索树的第K个节点
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
//面试题55题目二：判断是否是平衡二叉树
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
	//在遍历某节点的左右节点后，我们可以根据它的左右节点的深度判断它是不是平衡的，并得到当前节点的深度。当最后遍历到树的根节点时，
	//也就判断了整个二叉树是不是平衡的了
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
//面试题56题目二：数组中只有一个数出现1次，其他数出现3次
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
//面试题57题目一：和为s的数字
bool SumIsS(int *data, int length, int s, int *num1, int *num2) {
	//在递增数组中找到和为s的两个数，如果有多对，只输出一对
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
//面试题57题目二：和为s的连续正数序列
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
//面试题58题目一：翻转字符串
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
	//输入“I am a student.”，输出“student. a am I”
	if (data == nullptr)
		return;
	char *begin = data, *end = data;
	while (*end != '\0')
		++end;
	end--;
	Reverse(begin, end);
	begin = end = data;
	while (*begin != '\0') {
		if (*begin == ' ') {//这种情况是连续多个空格的情况
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
//面试题58题目二：翻转字符串
char* LeftRotateString(char *str,int n) {
	//输入“abcdefg”，输出“cdefgab”
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
//面试题61：扑克中的顺子
bool isContinue(int *data, int length) {
	//判断连续的n张牌是否是顺子，0可代替任意数
	int numberZero = 0;//0的个数
	int numberGap = 0;//间隔大小
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
//面试题62：圆圈中最后剩下的数字
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
//面试题63：股票的最大利润
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
//面试题65：不用加减乘除号进行两个数的相加
int SumWithBit(int num1, int num2) {
	int sum = 0;
	int carry = 0;
	do {
		sum = num1^num2;//只加不进位的
		carry = (num1&num2) << 1;//进位
		num1 = sum;
		num2 = carry;
	} while (carry != 0);
	return sum;
}
//面试题66：构建乘积数组
void mutiply(const vector<double>& input, vector<double>& output) {
	//题目：给定一个数组A[0, 1, …, n - 1]，请构建一个数组B[0, 1, …, n - 1]，其
	//中B中的元素B[i] = A[0]×A[1]×… ×A[i - 1]×A[i + 1]×…×A[n - 1]。不能使用除法。
	size_t length1 = input.size();
	size_t length2 = output.size();
	if (length1 == length2&&length2 > 1) {
		output[0] = 1;	//相当于c[0]
		for (int i = 1; i < length1; ++i) {
			output[i] = output[i - 1] * input[i - 1];
		}
		double temp = 1;//相当于d[n-1]
		for (size_t i = length1 - 2; i >= 0; --i) {
			temp *= input[i + 1];
			output[i] *= temp;
		}
	}
}
// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。
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

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）,用pattern去匹配str，'aaaaabb'和'a*bb'匹配，
//'*'表示它前面的字符可以出现任意次是值str里面的字符重复多次
bool match(const char* str, const char* pattern) {
	if (str == nullptr || pattern == nullptr)
		return false;
	return matchCore(str, pattern);
}
bool matchCore(const char* str, const char* pattern) {
	if (*str == '\0'&&*pattern == '\0')
		return true;
	if (*str != '\0'&&*pattern == '\0')//str还有，模式没了，肯定不匹配；要是str没了，模式还有是可能匹配的
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

//面试题二十：表示数值的字符串
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