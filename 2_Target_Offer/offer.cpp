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
	int length = strlen(number);
	for (int i = length - 1; i >= 0; --i) {
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
	int length = strlen(number);
	for (int i = 0; i < length; ++i) {
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