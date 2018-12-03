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
//������7���ؽ�������
//������10��쳲���������
long long Fibonacci(unsigned int n) {
	/*if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);*/
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long long a = 0;
	long long b = 1;
	long long c;
	for (int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}