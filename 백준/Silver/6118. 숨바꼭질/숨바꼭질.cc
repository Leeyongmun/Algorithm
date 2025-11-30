#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int n, m;
vector<int> v[20001];
int visited[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	visited[1] = 1;
	q.push(1);
	int ret = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) {
			if (visited[next]) continue;
			q.push(next);
			visited[next] = visited[cur] + 1;
			ret = max(ret, visited[next]);
		}
	}

	int hide = -1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == ret) {
			cnt++;
			if (hide == -1) hide = i;
		}
	}
	cout << hide << ' ' << ret - 1 << ' ' << cnt;
}