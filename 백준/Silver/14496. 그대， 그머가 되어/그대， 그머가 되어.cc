#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int a, b;
int n, m;

vector<int> graph[1001];
int visited[1001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	queue<int> q;
	visited[a] = 1;
	q.push(a);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == b) {
			cout << visited[b] - 1;
			return 0;
		}
		q.pop();
		for (int next : graph[cur]) {
			if (visited[next]) continue;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
	cout << -1;
}
          