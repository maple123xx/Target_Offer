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
	// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
	// ��ӡ��������֣������Կ�ͷ��0
	bool isFirst = true;
	int length = strlen(number);
	for (int i = 0; i < length; ++i) {
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