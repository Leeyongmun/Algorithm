#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n, x;
int a[1000001];
vector<int> v;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
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
	
	cin >> x;
	long long ret = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int GCD = gcd(x, a[i]);
		if (GCD == 1) {
			ret += a[i];
			cnt++;
		}
	}
	cout.precision(6);
	cout << fixed << (double)ret / cnt;
}