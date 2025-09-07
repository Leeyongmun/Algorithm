#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n;
vector<int> v[10001];
int t[10001];
int ind[10001];
int finish[10001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> t[i] >> m;
		for (int j = 0; j < m; j++) {
			int to;
			cin >> to;
			v[to - 1].push_back(i);
			ind[i]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			finish[i] = t[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) {
			ind[next]--;
			finish[next] = max(finish[next], finish[cur] + t[next]);
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(finish[i], ret);
	}
	cout << ret;
}