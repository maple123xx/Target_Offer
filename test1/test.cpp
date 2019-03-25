#include<iostream>
#include<string>
using namespace std;
//
//
//string Snake(string& str) {
//	int array[52];
//	for (int i = 0; i < 52; ++i) {
//		if(str.at(i)<='Z')
//			array[i]=
//	}
//}
//int main() {
//	
//	system("pause");
//	return 0;
//}

#include <numeric>                                       // For accumulate() - sums a range of elements
#include <iostream>                                      // For standard streams
//#include <iterator>                                      // For iterators and begin() and end()
#include<vector>
#include<memory>
#include<string>
using namespace std;
int main()
{
	unique_ptr<string> pname{ new string{"huangxixi"} };
	auto x = make_unique<string>(6,'h');
	auto y = x.get();
	cout << *y << endl;
}