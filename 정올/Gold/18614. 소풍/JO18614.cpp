#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
using namespace std;
using ll = long long;

int n;
ll ret = -(1LL << 60);

long long solve() {
	ll val;
	int cnt;

	cin >> val >> cnt;

	ll mx1 = 0, mx2 = 0;

	for (int i = 0; i < cnt; i++) {
		ll path = solve();
		if (path <= 0) continue;
		if (path > mx1) {
			mx2 = mx1;
			mx1 = path;
		}
		else if (path > mx2) {
			mx2 = path;
		}
	}

	ret = max(ret, val + mx1 + mx2);

	return val + mx1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	solve();

	cout << ret;
}
