#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	vector<int> visited(n + 1, -1);
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		visited[x] = 0;
		q.push(x);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur - 1 > 0 && visited[cur - 1] == -1) {
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 <= n && visited[cur + 1] == -1) {
			visited[cur + 1] = visited[cur] + 1;
			q.push(cur + 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << visited[i] << ' ';
	}
}
