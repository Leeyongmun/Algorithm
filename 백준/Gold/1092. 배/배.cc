#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n;
vector<int> v;
int m;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.rbegin(), v.rend());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}

	int cnt = m;
	bool flag = false;
	int ret = 0;
	while (!flag) {
		flag = true;
		for (int i = 0; i < n; i++) {
			auto it = mp.upper_bound(v[i]);
			if (it == mp.begin()) continue;
			flag = false;
			it--;
			it->second--;
			cnt--;
			if (it->second == 0) mp.erase(it);
		}
		ret++;
		if (cnt == 0) break;
	}
	if (cnt) cout << -1;
	else cout << ret;
}