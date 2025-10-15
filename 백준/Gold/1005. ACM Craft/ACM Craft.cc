#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<map>
#include<unordered_set>
#include<cstring>
using namespace std;

int T, n, k;
int a[100001];
int ind[100001];

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> k;
		memset(ind, 0, sizeof(int) * 100001);
		vector<vector<int>> v(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= k; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			ind[y]++;
		}
		queue<int> q;
		vector<int> dist(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				dist[i] = a[i];
			}
		}
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int next : v[cur]) {
				ind[next]--;
				dist[next] = max(dist[next], dist[cur] + a[next]);
				if (ind[next] == 0) {
					q.push(next);
				}
			}
		}
		int bui;
		cin >> bui;
		cout << dist[bui]<< '\n';
	}
}