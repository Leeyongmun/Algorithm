#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
int len = 1;
vector<int> tree;
vector<int> a, v;

void update(int idx) {
	idx += len;
	tree[idx]++;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

long long get(int idx, int s, int e, int ts, int te) {
	if (e < ts || s > te) return 0;
	else if (ts <= s && te >= e) return tree[idx];
	int mid = (s + e) / 2;
	return get(idx * 2, s, mid, ts, te) + get(idx * 2 + 1, mid + 1, e, ts, te);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());

	while (len < n) {
		len <<= 1;
	}
	tree.resize(len * 2);

	long long ret = 0;

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		
		if (idx + 1 <= n - 1) {
			ret += get(1, 0, len - 1, idx + 1, n - 1);
		}

		update(idx);
	}

	cout << ret;
}