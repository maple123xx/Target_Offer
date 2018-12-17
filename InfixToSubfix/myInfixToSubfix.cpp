#include"InfixToSubfix.h"
//����׺���ʽת��Ϊ��׺���ʽ����ͨ����׺���ʽ������׺���ʽ��ֵ

//�жϵ�ǰ�ַ��Ƿ�Ϊ����
bool isNumber(char s) {
	string opers = "+-/*()";		//����д��ԭ���ǲ��������ж�2+3��Ҳ�����ж�a+b
	for (int i = 0; i < opers.size(); ++i) {
		if (s == opers.at(i))
			return false;
	}
	return true;
}
//�жϵ�ǰ�������ջ������������ȼ���С
bool isPriorityLow(char currOper, char topOper) {
	if (currOper == '+' || currOper == '-') {
		if (topOper == '*' || topOper == '/' || topOper == '+' || topOper == '-')
			return true;
	}
	if (currOper == '*' || currOper == '/') {
		if (topOper == '*' || topOper == '/')
			return true;
	}
	return false;
}
//�����ǰ��������ȼ�С�ڻ����ջ�������, ��ջ������������ӵ���׺���ʽβ,
//���������бȽ�, ֱ����ǰ��������ȼ�����ջ����������ȼ�
void loopPushOperator(string& subfix, char oper, stack<char>& operators) {
	if (operators.size() > 0 && isPriorityLow(oper, operators.top())) {
		subfix += operators.top();
		operators.pop();
		loopPushOperator(subfix, oper, operators);
	}
}
//�ж��������ѹ�������ջ���Ǽӵ���׺���ʽβ
void handleOperator(string& subfix, char oper, stack<char>& operators) {
	switch (oper)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		if (operators.size() <= 0)	//��������ջΪ��, ֱ�ӽ���ǰ�����ѹջ
			operators.push(oper);
		else if (isPriorityLow(oper, operators.top())) {
			loopPushOperator(subfix, oper, operators);
			operators.push(oper);
		}
		else {						//�����ǰ��������ȼ�����ջ����������ȼ�, ����ǰ�����ѹջ
			operators.push(oper);
		}
		break;
	case '(':
		operators.push(oper);		//��ǰ�����Ϊ'('ֱ��ѹջ
		break;
	case ')':						//��ջ��Ԫ�ص����ӵ���׺���ʽβ,ֱ�����������"("
		while (operators.top() != '(') {
			subfix += operators.top();
			operators.pop();
		}
		operators.pop();
		break;
	default:
		break;
	}
}
//��׺���ʽת��׺���ʽ
string InfixToSubfix(string& infix) {
	stack<char> operators;	//�����ջ
	string subfix;	//��׺���ʽ
	for (int i = 0; i < infix.size(); ++i) {
		if (isNumber(infix.at(i)))		//�����֣�ֱ�Ӽӵ���׺��
			subfix += infix.at(i);
		else
			handleOperator(subfix, infix.at(i), operators);	//�������
	}
	if (subfix.length() > 0) {
		while (operators.size() > 0) {		//�������ջ�����е������ȫ����ջ�ӵ���׺���ʽβ
			subfix += operators.top();
			operators.pop();
		}
		return subfix;
	}
	else
		return "";
}
//���������,����ջ����������ֵ,���������ֵѹջ
void CaculateResult(char oper, stack<int>& numberStack) {
	if (numberStack.size() < 2)
		return;
	//ջ���Ƚ����,�����ȵ������ǵڶ���ֵ
	int secondValue = numberStack.top();
	numberStack.pop();
	int firstValue = numberStack.top();
	numberStack.pop();
	int result = 0;
	switch (oper)
	{
	case '+':
		result = firstValue + secondValue;
		break;
	case '-':
		result = firstValue - secondValue;
		break;
	case '*':
		result = firstValue * secondValue;
		break;
	case '/':
		result = firstValue / secondValue;
		break;
	default:
		break;
	}
	numberStack.push(result);
}
//ͨ����׺���ʽ������
//����׺���ʽ������ջ, ���Ϊ������, ����ջ������Ԫ�ؼ�������ѹ��ջ��
int getReslutUseSuffix(string& s) {
	if (s.length() <= 0)
		return 0;
	stack<int> numberStack;
	for (int i = 0; i < s.length(); ++i) {
		if (isNumber(s.at(i)))
			numberStack.push(s.at(i)-'0');//����3��ת��Ϊint������ջ
		else {
			CaculateResult(s.at(i), numberStack);
		}
	}
	return numberStack.top();	//����ջ��ֵ��Ϊ���ʽ��ֵ
}
