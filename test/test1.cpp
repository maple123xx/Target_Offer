#include<iostream>
#include<stack>
#include<string>
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
int main() {
	string str = "1+2+99-10-1";
	int result = cal(str);
	cout << "result=" <<result<< endl;
	return 0;
}