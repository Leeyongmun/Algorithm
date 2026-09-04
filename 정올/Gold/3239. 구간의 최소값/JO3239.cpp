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
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n, m;
int len = 1;
vector<int> tree;
vector<int> a;
const int INF = 2e9;

int mergeIdx(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;

	if (a[x] != a[y]) {
		return a[x] < a[y] ? x : y;
	}

	return min(x, y);
}

void update(int idx, int val) {
	a[idx] = val;

	idx += len - 1;

	if (val == INF) tree[idx] = -1;
	else tree[idx] = idx - len + 1;

	idx /= 2;

	while (idx >= 1) {
		tree[idx] = mergeIdx(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}

int get(int idx, int s, int e, int ts, int te) {
	if (e < ts || s > te) return -1;
	if (ts <= s && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	int l = get(idx * 2, s, mid, ts, te);
	int r = get(idx * 2 + 1, mid + 1, e, ts, te);
	return mergeIdx(l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	while (len < n) len <<= 1;

	tree.assign(len * 2, -1);
	a.assign(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if (cmd == 1) {
			update(x, y);
		}

		if (cmd == 2) {
			int idx = get(1, 1, len, x, y);

			if (idx != -1) {
				cout << idx << '\n';
			}
		}

		if (cmd == 3) {
			int idx = get(1, 1, len, x, y);

			if (idx != -1) {
				update(idx, INF);
			}
		}
	}
}
