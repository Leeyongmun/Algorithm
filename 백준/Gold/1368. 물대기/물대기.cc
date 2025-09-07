#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n;
vector<pair<int, int>> edge[301];
bool visited[301];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		edge[0].push_back({ w, i });
		edge[i].push_back({ w, 0 });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i == j) continue;
			edge[i].push_back({ cost, j });
		}
	}
	vector<int> minEdge(n + 1, 987654321);
	priority_queue<pair<int, int>> pq;
	minEdge[1] = 0;
	pq.push({ 0, 1 });
	int cnt = 0;
	int ret = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		cnt++;
		ret += cost;
		if (cnt == n + 1) break;
		for (auto next : edge[cur]) {
			if (!visited[next.second] && minEdge[next.second] > next.first) {
				minEdge[next.second] = next.first;
				pq.push({ -next.first, next.second });
			}
		}
	}
	cout << ret;
}