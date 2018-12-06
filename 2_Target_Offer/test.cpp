#include"offer.h"

int main() {
	/*int A[] = { 1,3,4,4,6,2,5,0 };
	int duplicate;
	int length = sizeof(A)/sizeof(A[0]);
	bool result = Duplicate(A, length,&duplicate);
	if (result)
		cout << "重复的数字的是：" << duplicate << endl;
	else
		cout << "无重复的数字" << endl;*/
	/*int A[] = { 2,2,1,5,4,3,6,7 };
	int duplicate = Duplicate2(A, 8);
	cout << "重复的数字的是：" << duplicate << endl;*/
	//int A[] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	//int A[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	//bool found = Matrix_Find((int *)A, 4, 4, 12);//这样传二维数组，将二维指针强制转换为一维指针
	//cout << found << endl;
	/*char str[100] = "Weare  happy! ";
	ReplaceBlank(str);
	for (int i = 0; str[i] != '\0'; ++i) {
		cout << str[i];
	}
	cout << endl;*/
	/*int A[100] = { 1,2,4,6,7,8 };
	int B[10] = { 3,5,6,7,8,10,11 };
	int a = 6;
	int b = 7;
	copyBtoA(A, B,a,b);
	for (int i = 0; i < (a + b); ++i) {
		cout << A[i] << '\t';
	}
	cout << endl;*/
	/*long long fib = Fibonacci(12);
	cout << fib << endl;*/
	/*int A[10] = {1};
	cout << Rotate_Min(A, 1) << endl;*/
	/*const char* matrix = "abcesfcsadee";
	const char* str = "see";
	bool result=HasPath((const char*)matrix, 3, 4, (const char*)str);
	if (result)
		cout << "存在路径" << endl;
	else
		cout << "不存在路径" << endl;*/
	/*int count = robotRoad(8, 40, 40);
	cout << "能到达的格子数：" <<count<< endl;*/
	cout << "绳子长度乘积最大为：" << maxProductAfterCutting2(8) << endl;
	cout << "1的个数为" << numberOf1_2(-1) << endl;;
	return 0;
}