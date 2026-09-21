#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n, q, x;
vector<int> graph[100001];
vector<int> inv[100001];
bool visited[100001];

int dfs(int cur, vector<int>* v) {
	int cnt = 1;
	visited[cur] = true;

	for (int next : v[cur]) {
		if (visited[next]) continue;
		cnt += dfs(next, v);
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q >> x;

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inv[b].push_back(a);
	}

	memset(visited, false, sizeof(visited));
	int hi = dfs(x, inv);

	memset(visited, false, sizeof(visited));
	int lo = dfs(x, graph);

	cout << hi << ' ' << n - lo + 1;
}
