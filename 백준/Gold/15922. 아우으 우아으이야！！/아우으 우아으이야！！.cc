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

int n;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	int l, r;
	cin >> l >> r;
	v.push_back({ l,r });
	for (int i = 1; i < n; i++) {
		cin >> l >> r;
		int idx = v.size() - 1;
		if (v[idx].second >= l) {
			v[idx].second = max(v[idx].second, r);
		}
		else v.push_back({ l, r });
	}
	int ret = 0;
	for (auto p : v) {
		ret += p.second - p.first;
	}
	cout << ret;
}