#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n, s, g, u, d;

int main() {
	cin >> n >> s >> g >> u >> d;
	vector<int> visited(n + 1, 0);
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == g) break;
		if (cur + u <= n && !visited[cur + u]) {
			q.push(cur + u);
			visited[cur + u] = visited[cur] + 1;
		}
		if (cur - d >= 1 && !visited[cur - d]) {
			q.push(cur - d);
			visited[cur - d] = visited[cur] + 1;
		}
	}
	if (visited[g]) cout << visited[g] - 1;
	else cout << "use the stairs";
}