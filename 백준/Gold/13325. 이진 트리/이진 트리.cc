#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<int> tree, dp;
int ret = 0;
int p = 0;

int dfs(int cur) {
	if (cur >= pow(2, n)) {
		return tree[cur];
	}
	int left = dfs(cur * 2);
	int right = dfs(cur * 2 + 1);
	if (right > left) {
		p += right - left;
		left += right - left;
	}
	else {
		p += left - right;
		right += left - right;
	}
	return left + tree[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int len = 2 * pow(2, n);
	tree.resize(len);
	dp.resize(len);
	tree[1] = 0;
	int sum = 0;
	for (int i = 2; i < len; i++) {
		cin >> tree[i];
		sum += tree[i];
	}
	dfs(1);
	cout << sum + p;
}

