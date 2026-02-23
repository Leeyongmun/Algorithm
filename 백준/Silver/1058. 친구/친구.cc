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

int n;
vector<int> graph[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < n; i++) {
		vector<int> dist(n, -1);
		queue<int> q;

		dist[i] = 0;
		q.push(i);
		int cnt = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : graph[cur]) {
				if (dist[next] != -1) continue;
				dist[next] = dist[cur] + 1;

				if (dist[next] <= 2) {
					cnt++;
					q.push(next);
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret;
}