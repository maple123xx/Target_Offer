#include"InfixToSubfix.h"

int main() {
	string infix;
	stack<char> operators;
	cout << "请输入中缀表达式" << endl;
	cin >> infix;
	string subfix = InfixToSubfix(infix);
	cout << "后缀表达式为" << endl;
	cout << subfix << endl;
	cout << "后缀表达式的值为" << endl;
	cout << getReslutUseSuffix(subfix) << endl;
	return 0;
}