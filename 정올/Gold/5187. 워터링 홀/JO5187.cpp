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
int p[301][301];
bool visited[301];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p[i][0] = x;
		p[0][i] = x;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> p[i][j];
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, 1 });

	int ret = 0;
	int cnt = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue;

		visited[cur] = true;
		ret += cost;
		cnt++;

		if (cnt == n + 1) break;

		for (int i = 0; i <= n; i++) {
			if (visited[i]) continue;
			pq.push({p[cur][i], i});
		}
	}

	cout << ret;
}
