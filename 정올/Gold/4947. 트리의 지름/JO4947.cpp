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

int n;
vector<int> graph[100001];
int len = 0, idx = -1;

void dfs(int cur, int parent, int l) {
	if (l > len) {
		len = l;
		idx = cur;
	}

	for (int next : graph[cur]) {
		if (next == parent) continue;
		dfs(next, cur, l + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, -1, 0);
	dfs(idx, -1, 0);

	cout << len;
}
