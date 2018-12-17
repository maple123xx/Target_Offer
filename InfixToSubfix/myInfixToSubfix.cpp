#include"InfixToSubfix.h"
//将中缀表达式转化为后缀表达式，并通过后缀表达式的求中缀表达式的值

//判断当前字符是否为数字
bool isNumber(char s) {
	string opers = "+-/*()";		//这样写的原因是不仅可以判断2+3，也可以判断a+b
	for (int i = 0; i < opers.size(); ++i) {
		if (s == opers.at(i))
			return false;
	}
	return true;
}
//判断当前运算符与栈顶运算符的优先级大小
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
//如果当前运算符优先级小于或等于栈顶运算符, 将栈顶运算符弹出加到后缀表达式尾,
//并继续进行比较, 直到当前运算符优先级大于栈顶运算符优先级
void loopPushOperator(string& subfix, char oper, stack<char>& operators) {
	if (operators.size() > 0 && isPriorityLow(oper, operators.top())) {
		subfix += operators.top();
		operators.pop();
		loopPushOperator(subfix, oper, operators);
	}
}
//判断运算符是压入运算符栈还是加到后缀表达式尾
void handleOperator(string& subfix, char oper, stack<char>& operators) {
	switch (oper)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		if (operators.size() <= 0)	//如果运算符栈为空, 直接将当前运算符压栈
			operators.push(oper);
		else if (isPriorityLow(oper, operators.top())) {
			loopPushOperator(subfix, oper, operators);
			operators.push(oper);
		}
		else {						//如果当前运算符优先级大于栈顶运算符优先级, 将当前运算符压栈
			operators.push(oper);
		}
		break;
	case '(':
		operators.push(oper);		//当前运算符为'('直接压栈
		break;
	case ')':						//将栈中元素弹出加到后缀表达式尾,直到遇到运算符"("
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
//中缀表达式转后缀表达式
string InfixToSubfix(string& infix) {
	stack<char> operators;	//运算符栈
	string subfix;	//后缀表达式
	for (int i = 0; i < infix.size(); ++i) {
		if (isNumber(infix.at(i)))		//是数字，直接加到后缀上
			subfix += infix.at(i);
		else
			handleOperator(subfix, infix.at(i), operators);	//处理符号
	}
	if (subfix.length() > 0) {
		while (operators.size() > 0) {		//将运算符栈中留有的运算符全部出栈加到后缀表达式尾
			subfix += operators.top();
			operators.pop();
		}
		return subfix;
	}
	else
		return "";
}
//根据运算符,计算栈顶两个数的值,并将计算的值压栈
void CaculateResult(char oper, stack<int>& numberStack) {
	if (numberStack.size() < 2)
		return;
	//栈是先进后出,所以先弹出的是第二个值
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
//通过后缀表达式计算结果
//将后缀表达式依次入栈, 如果为操作符, 弹出栈中两个元素计算结果再压入栈中
int getReslutUseSuffix(string& s) {
	if (s.length() <= 0)
		return 0;
	stack<int> numberStack;
	for (int i = 0; i < s.length(); ++i) {
		if (isNumber(s.at(i)))
			numberStack.push(s.at(i)-'0');//将‘3’转化为int后再入栈
		else {
			CaculateResult(s.at(i), numberStack);
		}
	}
	return numberStack.top();	//最后的栈顶值即为表达式的值
}
