#include"InfixToSubfix.h"

int main() {
	string infix;
	stack<char> operators;
	cout << "��������׺���ʽ" << endl;
	cin >> infix;
	string subfix = InfixToSubfix(infix);
	cout << "��׺���ʽΪ" << endl;
	cout << subfix << endl;
	cout << "��׺���ʽ��ֵΪ" << endl;
	cout << getReslutUseSuffix(subfix) << endl;
	return 0;
}