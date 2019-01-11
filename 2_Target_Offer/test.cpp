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
	/*cout << "绳子长度乘积最大为：" << maxProductAfterCutting2(8) << endl;
	cout << "1的个数为" << numberOf1_2(-1) << endl;
	if (isPowerOf2(15))
		cout << "是2的幂" << endl;*/
	//cout << "需要改变的bit数为：" << changeBit(2,13) << endl;
	//unsigned int a = (unsigned int)(-1);
	//cout << a << endl;				//输出为429467295，即2的32次方减1,因为-1以补码形式存储，除符号位，取反加1，
	//cout << pow(2, 32) - 1 << endl;	//也就是变成32个1了，再强制转为无符号数，就是这个结果
	/*bool invalidInput = false;
	double result = power(2, 5, invalidInput);
	if (!invalidInput)
		cout << "输入合法，幂值为：" << result << endl;
	else
		cout << "底数为0，且指数为负数，无意义" << endl;*/
	//Print1ToMaxOfNDigits_2(3);
	/*BTNode *pNode8 = CreateBTNode(8);
	BTNode *pNode8_2 = CreateBTNode(8);
	BTNode *pNode7 = CreateBTNode(7);
	BTNode *pNode9 = CreateBTNode(9);
	BTNode *pNode2 = CreateBTNode(2);
	BTNode *pNode4 = CreateBTNode(4);
	BTNode *pNode7_2 = CreateBTNode(7);*/
	/*BTNode *pNode8_3 = CreateBTNode(8);
	BTNode *pNode9_2 = CreateBTNode(9);
	BTNode *pNode2_2 = CreateBTNode(2);*/
	/*ConnectTreeNode(pNode8, pNode8_2, pNode7);
	ConnectTreeNode(pNode8_2, pNode9, pNode2);
	ConnectTreeNode(pNode2, pNode4, pNode7_2);
	LevelPrint3(pNode8);*/
	//ConnectTreeNode(pNode8_3, pNode9_2, pNode2_2);
	////ConnectTreeNode(pNode4, nullptr, pNode2);
	//PreOrder(pNode8);
	//cout << endl;
	//PreOrder(pNode8_3);
	//cout << endl;
	//bool result = HasSubtree(pNode8, pNode8_3);
	//if (result)
	//	cout << "B是A的子结构" << endl;
	/*BTNode *pNode8 = CreateBTNode(8);
	BTNode *pNode6 = CreateBTNode(3);
	BTNode *pNode6_2 = CreateBTNode(6);
	BTNode *pNode5 = CreateBTNode(5);
	BTNode *pNode7 = CreateBTNode(7);
	BTNode *pNode7_2 = CreateBTNode(7);
	BTNode *pNode5_2 = CreateBTNode(5);
	ConnectTreeNode(pNode8, pNode6, pNode6_2);
	ConnectTreeNode(pNode6, pNode5, pNode7);
	ConnectTreeNode(pNode6_2, pNode7, pNode5);
	if (isSymmetry(pNode8))
		cout << "是对称的" << endl;*/
	/*int pPush[] = { 1,2,3,4,5 };
	int pPop[] = { 4,5,3,2,1 };
	if (isPopOrder(pPush, pPop, 5))
		cout << "是正确的弹出序列" << endl;
	else
		cout << "不是正确的弹出序列" << endl;*/
	//int Sequence[] = { 5,7,6,9,11,10,8 };
	/*int Sequence[] = { 7,4,6,5 };
	if (VerifySequenceOfBST(Sequence, 4))
		cout << "是后续遍历序列" << endl;
	else
		cout << "不是" << endl;*/
	/*int num[] = { 1,2,3,2,2,2};
	int result = MoreThanHalfNum2(num, 6);
	cout << "超过数组一半的数字是：" << result << endl;*/

	//int input[] = { 4,5,1,6,2,7,3,8,1,2,7,8,2,1,4};
	//int output[20];
	////GetLeastNumber(input, 12, output, 4);
	///*for (int i = 0; i < 4; ++i) {
	//	cout << output[i] << '\t';
	//}*/
	//vector<int> data;
	//for (int i = 0; i < sizeof(input) / sizeof(input[0]); ++i) {
	//	data.push_back(input[i]);
	//}
	//intSet leastNumbers;
	//GetLeastNumber2(data, leastNumbers, 4);
	//for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter) {
	//	cout << *iter << '\t';
	//}
	//cout << endl;
	/*DynamicArray<double> dymArray;
	dymArray.insert(5);
	dymArray.insert(2);
	dymArray.insert(3);
	dymArray.insert(4);
	dymArray.insert(1);
	cout << dymArray.GetMidium() << endl;
	int data[] = { -2,-8,-1,-5,-9 };
	cout << FindGreatestSumOfSubArray(data, sizeof(data)/sizeof(data[0]))<<endl;*/
	//cout << NumberOf1Between1AndN(15) << endl;
	cout << digitAtIndex2(20) << endl;
	return 0;
}