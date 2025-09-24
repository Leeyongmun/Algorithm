#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> dist(1000001, 987654321);
queue<int> q;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		q.push(num);
		dist[num] = 0;
	}
	int ret = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 20; i++) {
			int x = cur ^ (1 << i);
			if (x > n || dist[x] != 987654321) continue;
			q.push(x);
			dist[x] = dist[cur] + 1;
			ret = max(ret, dist[x]);
		}
	}
	cout << ret;
}