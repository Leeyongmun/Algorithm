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

int n, k;
vector<vector<pair<int, int>>> graph;
vector<int> sub;
vector<int> parent;
unordered_set<int> st;

void dfs(int c, int pa) {
	parent[c] = pa;
	sub[c] = st.count(c) ? 1 : 0;

	for (auto p : graph[c]) {
		int next = p.first;
		int cost = p.second;

		if (next == pa) continue;

		dfs(next, c);
		sub[c] += sub[next];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	graph.resize(n + 1);
	sub.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}

	dfs(1, 0);

	int ret = 0;

	for (int i = 1; i <= n; i++) {
		bool isGood = true;

		if (parent[i] != 0) {
			if (sub[i] == 0) isGood = false;
		}

		for (auto p : graph[i]) {
			int next = p.first;
			int cost = p.second;

			if (parent[i] == next) continue;

			if (k - sub[next] == 0) {
				isGood = false;
				break;
			}
		}

		if (isGood) ret++;
	}

	cout << ret;
}
