#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
#include<cmath>
#include<queue>
using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<pair<double, int>> graph[1001];
bool visited[1001];

int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double cost = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
			graph[i].push_back({ cost, j });
			graph[j].push_back({ cost, i });
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({ 0, b });
		graph[b].push_back({ 0, a });
	}
	double ret = 0;
	int cnt = 0;

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		double cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;
		visited[cur] = true;
		ret += cost;
		cnt++;
		
		if (cnt == n) break;

		for (auto p : graph[cur]) {
			if (!visited[p.second]) {
				pq.push(p);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ret;
}