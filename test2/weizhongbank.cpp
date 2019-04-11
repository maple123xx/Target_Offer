////#include<iostream>
////#include<algorithm>
////#include<utility>
////#include<vector>
////#include<set>
////#include<string>
////#include<deque>
////#include<stack>
////#include<queue>
////#include<map>
////#include<bitset>
////using namespace std;
////
////int main() {
////	/*int n;
////	cin >> n;
////	vector<int> array;
////	int temp;
////	for (int i = 0; i < n; i++)
////	{
////		cin >> temp;
////		array.push_back(temp);
////	}*/
////	/*int i;
////	while (cin >> i) {
////		
////		array.push_back(i);
////	}*/
////	int N;
////	cin >> N;
////	cout << bitset<sizeof(N) * 8>(N) << endl;
////	
////	cout << endl;
////}
//
//
////#include<iostream>
////using namespace std;
////int main() {
////	int a, b, c, count = 0;
////	cin >> a >> b >> c;
////	long long A = 2 << a, B = 2 << b, C = 2 << c;
////	long long D = A + B - C;
////	while (D > 0) {
////		if (D % 2 == 1) {
////			++count;
////		}
////		D = D / 2;
////	}
////	cout << count;
////	return 0;
////}
//
////#include<iostream>
////#include<vector>
////using namespace std;
////
////bool IsHuiWen(long long n)
////{
////	vector<int> a;
////	while (n >= 0)
////	{
////		a.push_back(n % 2);
////		n = n / 2;
////		if (n == 0) {
////			break;
////		}
////	}
////	long long i, j;
////	for (i = 0, j = a.size() - 1; i < j; ++i, --j)
////	{
////		if (a[i] != a[j])
////		{
////			return false;
////		}
////	}
////	return true;
////}
////
////int main()
////{
////	long long N;
////	cin >> N;
////	int num = 0;
////	for (long long x = 0; x <= N; ++x) {
////		if (IsHuiWen(x)) {
////			++num;
////		}
////	}
////	cout << num << endl;
////
////	return 0;
////}
//
//
//
////StringBuilder result = new StringBuilder();
////StringBuilder prime = new StringBuilder();
////for (int i = 2; i <= n; i++) {
////	if (isPrime(i)) {
////		result.append(i);
////		prime.append(i);
////	}
////	else {
////		for (int j = 0; i<prime.length(); j++) {
////			if (isfield(i, prime.charAt(j))) {
////				result.append(i);
////			}
////		}
////	}
////}
////
////	}
////
////	public static boolean isfield(int n, int a) {
////		while (n >= a) {
////			if (n%a != 0) {
////				return false;
////			}
////			else {
////				n = n / a;
////			}
////		}
////		if (n == 1)return true;
////		else {
////			return false;
////		}
////	}
////
////
////
////	public static boolean isPrime(int i) {
////		boolean flag = true;
////		for (int j = 2; j < i; j++) {
////			if (i%j == 0) {
////				flag = false;
////			}
////		}
////		return flag;
////	}
//
//
////#include <iostream>
////#include <math.h>
////#include <vector>
////using namespace std;
////bool isPrime(int n);
////vector<int> find_sushu(int n);
////int count_youxianyu(int n);
////int count_youxianyu(int n)
////{
////	if (n == 1)
////		return 0;
////	int count_yu = 0;
////	vector<int> v = find_sushu(n);
////	int i = 0;
////	while (i<v.size())
////	{
////		for (int j = 1; pow(v[i], j) <= n; ++j)
////		{
////			count_yu++;
////		}
////		++i;
////	}
////	return count_yu;
////}
////
////bool isPrime(int n)
////{
////	bool flag = true;
////	if (n == 1)
////		flag = false;
////	for (int i = 2; i <= n / 2; ++i)
////	{
////		if (n%i == 0)
////		{
////			flag = false;
////			break;
////		}
////	}
////	return flag;
////}
////
////vector<int> find_sushu(int n)
////{
////	vector<int> v;
////	for (int i = 2; i <= sqrt(n); ++i) {
////		if (isPrime(i))
////		{
////			v.push_back(i);
////		}
////	}
////	return v;
////}
////
////int main()
////{
////	int n;
////	cin >> n;
////	cout << count_youxianyu(n) << endl;
////	return 0;
////}

#include<iostream>

using namespace std;

short a[26];

int main()
{
	long long N;
	cin >> N;
	int num = 0;
	for (long long x = 0; x <= N; ++x) {
		long long n = x;
		int flag = 1;

		int i = 0;
		for (i = 0; n >= 0; ++i) {
			a[i] = n % 2;
			n = n >> 1;
			if (n == 0) {
				break;
			}
		}

		int j = i;
		for (i = 0; i < j; ++i, --j) {
			if (a[i] != a[j]) {
				flag = 0;
				break;
			}
		}

		num += flag;
	}
	cout << num << endl;
	return 0;
}