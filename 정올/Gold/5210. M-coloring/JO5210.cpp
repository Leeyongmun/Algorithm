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

int n, m, k;
vector<int> graph[11];
int color[11];
int ret = 0;

bool canPaint(int cur, int col) {
	for (int x : graph[cur]) {
		if (color[x] == col) return false;
	}
	return true;
}

void dfs(int cur) {
	if (cur > n) {
		ret++;
		return;
	}

	for (int i = 1; i <= m; i++) {
		if (!canPaint(cur, i)) continue;
		color[cur] = i;
		dfs(cur + 1);
		color[cur] = 0;
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);
	cout << ret;
}
