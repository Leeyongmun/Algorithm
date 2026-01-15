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

int n, m, s;
vector<int> graph[100001];
unordered_set<int> st;
bool flag = false;

void dfs(int cur) {
	if (!graph[cur].size()) flag = true;
	for (int next : graph[cur]) {
		if (!st.count(next)) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a;
		cin >> a;
		st.insert(a);
	}

	if (st.count(1)) {
		cout << "Yes";
		return 0;
	}
	dfs(1);
	if (flag) cout << "yes";
	else cout << "Yes";
}