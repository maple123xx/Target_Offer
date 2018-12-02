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