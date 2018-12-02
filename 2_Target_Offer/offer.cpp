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
		if (count > (mid - start + 1))
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