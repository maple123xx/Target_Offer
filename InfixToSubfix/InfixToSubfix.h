#ifndef InfixToSubfix_
#define InfixToSubfix_
#include"myNamespace.h"

bool isNumber(char s);
bool isPriorityLow(char currOper, char topOper);
void loopPushOperator(string& subfix, char oper, stack<char>& operators);
void handleOperator(string& subfix, char oper, stack<char>& operators);
string InfixToSubfix(string& infix);
void CaculateResult(char oper, stack<int>& numberStack);
int getReslutUseSuffix(string& s);
#endif // !InfixToSubfix_

