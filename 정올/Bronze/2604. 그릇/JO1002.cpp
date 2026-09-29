#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n;
int a[11];

int GCD(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int gcd = a[0];
	int lcm = a[0];

	for (int i = 1; i < n; i++) {
		gcd = GCD(gcd, a[i]);

		int g = GCD(lcm, a[i]);
		lcm = lcm / g * a[i];
	}

	cout << gcd << ' ' << lcm;
}