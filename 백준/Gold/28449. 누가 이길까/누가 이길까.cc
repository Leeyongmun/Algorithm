#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n, m;
vector<int> a, b;
long long w = 0, l = 0, d = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		auto x = lower_bound(b.begin(), b.end(), a[i]);
		auto y = upper_bound(b.begin(), b.end(), a[i]);
		int cd = y - x;
		int cw = x - b.begin();
		int cl = b.end() - y;
		w += cw;
		d += cd;
		l += cl;
	}
	cout << w << ' ' << l << ' ' << d;
}