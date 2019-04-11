//#include<iostream>
//#include<string>
//using namespace std;
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

#include "myNamespace.h"

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

int main() {
	set<int> a{ 0,1,4,2,3,8,2 };
	a.insert(7);
	for (const auto&i : a) {
		cout << i << '\t';
	}
	
	
	cout <<endl;
	return 0;
}

#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<map>
using namespace std;

int main() {
	/*int n;
	cin >> n;
	vector<int> array;
	int temp;
	for (int i = 0; i < n; i++)
	{
	cin >> temp;
	array.push_back(temp);
	}*/
	/*int i;
	while (cin >> i) {

	array.push_back(i);
	}*/
	map<int, int> arr;
	int n, m;
	while (cin >> n >> m) {
		//arr[n] = m;
		arr.insert(make_pair(n, m));
	}
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		//for(int i=0;i<it->)
		cout << it->first << '\t' << it->second << endl;
	}
	//pair<int, int> a;


	cout << endl;
}