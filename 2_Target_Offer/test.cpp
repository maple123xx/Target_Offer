#include"offer.h"

int main() {
	/*int A[] = { 1,3,4,4,6,2,5,0 };
	int duplicate;
	int length = sizeof(A)/sizeof(A[0]);
	bool result = Duplicate(A, length,&duplicate);
	if (result)
		cout << "�ظ������ֵ��ǣ�" << duplicate << endl;
	else
		cout << "���ظ�������" << endl;*/
	int A[] = { 2,1,5,4,3,6,7 };
	int duplicate = Duplicate2(A, 7);
	cout << "�ظ������ֵ��ǣ�" << duplicate << endl;
	return 0;
}