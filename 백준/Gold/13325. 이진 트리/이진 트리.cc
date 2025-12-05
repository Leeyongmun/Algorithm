#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<int> tree;
int ret = 0;
int p = 0;
int len = 0;

int dfs(int cur) {
	if (cur * 2 > len - 1) return 0;
	int left = dfs(cur * 2) + tree[cur * 2];
	int right = dfs(cur * 2 + 1) + tree[cur * 2 + 1];
	ret += abs(right - left);
	return max(left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	len = 1 << (n + 1);
	tree.resize(len);
	int sum = 0;
	for (int i = 2; i < len; i++) {
		cin >> tree[i];
		sum += tree[i];
	}
	dfs(1);
	cout << sum + ret;
}

