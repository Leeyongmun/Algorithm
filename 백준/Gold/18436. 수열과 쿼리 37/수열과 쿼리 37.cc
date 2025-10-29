#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>

using namespace std;

int n, m;
int len;
vector<int> oddTree, evenTree;

void update(int idx, int val) {
	idx += len;
	if (val % 2 == 0) {
		evenTree[idx] = 1;
		oddTree[idx] = 0;
	}
	else {
		evenTree[idx] = 0;
		oddTree[idx] = 1;
	}

	idx /= 2;
	while (idx > 0) {
		evenTree[idx] = evenTree[idx * 2] + evenTree[idx * 2 + 1];
		oddTree[idx] = oddTree[idx * 2] + oddTree[idx * 2 + 1];
		idx /= 2;
	}
}

int get(vector<int>& tree, int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	else if (ts <= s && e <= te) return tree[idx];
	int mid = (s + e) / 2;
	int l = get(tree, idx * 2, s, mid, ts, te);
	int r = get(tree, idx * 2 + 1, mid + 1, e, ts, te);
	return l + r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	len = 1;
	while (len < n) len <<= 1;
	oddTree.resize(2 * len);
	evenTree.resize(2 * len);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num % 2 == 0) {
			evenTree[i + len] = 1;
		}
		else oddTree[i + len] = 1;
	}
	for (int i = len - 1; i > 0; i--) {
		evenTree[i] = evenTree[i * 2] + evenTree[i * 2 + 1];
		oddTree[i] = oddTree[i * 2] + oddTree[i * 2 + 1];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update(a - 1, b);
		}
		else if (cmd == 2) {
			cout << get(evenTree, 1, 0, len - 1, a - 1, b - 1) << '\n';
		}
		else {
			cout << get(oddTree, 1, 0, len - 1, a - 1, b - 1) << '\n';
		}
	}

}