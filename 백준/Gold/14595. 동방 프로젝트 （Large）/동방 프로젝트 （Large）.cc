#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
using namespace std;

int n, m;
map<int, int> mp;
int broken = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		r--;
		int nl = l;
		int nr = r;

		auto it = mp.upper_bound(l);

		if (it != mp.begin()) {
			it--;
			if (it->second < l) it++;
		}

		while (it != mp.end() && it->first <= r) {
			nr = max(nr, it->second);
			nl = min(nl, it->first);
			broken -= (it->second - it->first + 1);
			it = mp.erase(it);
		}
		mp[nl] = nr;
		broken += (nr - nl + 1);
	}
	cout << n - broken;
}