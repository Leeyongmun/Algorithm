#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
int check[100001];
vector<int> graph[100001];
vector<int> ans;
vector<int> ret;
int order[100001];

bool cmp(int a, int b) {
	return order[a] < order[b];
}

void dfs(int x, int parent) {
	if (check[x]) return;
	check[x] = 1;
	ret.push_back(x);
	for (int next : graph[x]) {
		if (next == parent) continue;
		if (check[next]) continue;
		dfs(next, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	ans.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		order[ans[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	dfs(1, -1);

	for (int i = 0; i < n; i++) {
		if (ans[i] != ret[i]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
}