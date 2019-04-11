#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

//判断当前字符是否为数字
bool isNumber(char s) {
	string opers = "+-";		
	for (int i = 0; i < opers.size(); ++i) {
		if (s == opers.at(i))
			return false;
	}
	return true;
}
//计算
int cal(const string& str) {
	int sum = 0;
	stack<char> operators;	//运算符栈
	for (int i = 0; i < str.size()-1;) {
		if (isNumber(str.at(i))&&operators.size()==0) {
			if (isNumber(str.at(i + 1))) {
				sum += (10 * (str.at(i) - '0') + (str.at(i + 1) - '0'));
				i = i + 2;
			}
			else {
				sum += (str.at(i) - '0');
				i = i + 1;
			}
		}
		else if(isNumber(str.at(i)) && operators.size() != 0){
			if (operators.top() == '+') {
				if (isNumber(str.at(i + 1))) {
					sum += (10 * (str.at(i) - '0') + (str.at(i + 1) - '0'));
					i = i + 2;
				}
				else {
					sum += (str.at(i) - '0');
					i = i + 1;
				}
			}
			else {
				if (isNumber(str.at(i + 1))) {
					sum -= (10 * (str.at(i) - '0') + (str.at(i + 1) - '0'));
					i = i + 2;
				}
				else {
					sum -= (str.at(i) - '0');
					i = i + 1;
				}
			}
			operators.pop();
		}
		else {
			operators.push(str.at(i));
			++i;
		}		
	}
	return sum;
}

inline size_t precedence(const char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	throw std::runtime_error{ string{ "invalid operator in precedence() function: " } +op };
}
double execute(std::stack<char>& ops, std::stack<double>& operands)
{
	double result{};
	double rhs{ operands.top() };                            // Get rhs...
	operands.pop();                                         // ...and delete from stack
	double lhs{ operands.top() };                            // Get lhs...
	operands.pop();                                         // ...and delete from stack

	switch (ops.top())                                      // Execute current op
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '/':
		result = lhs / rhs;
		break;
	case '^':
		result = std::pow(lhs, rhs);
		break;
	default:
		throw std::runtime_error{ string{ "invalid operator in execute() function: " } +ops.top() };
	}
	ops.pop();                                              // Delete op just executed
	operands.push(result);
	return result;
}
int main() {
	/*string str = "12+2+99-10-1";
	int result = cal(str);
	cout << "result=" <<result<< endl;*/
	string str = "1.2+2+99-10-1";
	stack<double> num;
	stack<char> op;

	size_t index=0;
	num.push(stod(str, &index));
	while (true) {
		op.push(str[index++]);
		size_t i = 0;
		num.push(stod(str.substr(index), &i));
		index += i;
		if (index == str.length()) {
			while (!op.empty())
				num.push(execute(op, num));
			break;
		}
		while (!op.empty() && precedence(str[index]) <= precedence(op.top()))
			num.push(execute(op, num));
		
	}
	cout << "result = " << num.top() << endl;
	return 0;
}