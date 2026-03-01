#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;
int T;
int n, m, k;
vector<pair<int, pair<int,int>>> graph[101];
int dist[101][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {

        cin >> n >> m >> k;

        for (int i = 1; i <= n; i++)
            graph[i].clear();

        for (int i = 0; i < k; i++) {
            int from, to, c, d;
            cin >> from >> to >> c >> d;
            graph[from].push_back({to, {c, d}});
        }

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dist[i][j] = INF;

        dist[1][0] = 0;

        for (int cost = 0; cost <= m; cost++) {
            for (int u = 1; u <= n; u++) {
                if (dist[u][cost] == INF) continue;

                for (auto &p : graph[u]) {
                    int next = p.first;
                    int ncost = cost + p.second.first;
                    int ndist = dist[u][cost] + p.second.second;

                    if (ncost > m) continue;

                    dist[next][ncost] = min(dist[next][ncost], ndist);
                }
            }
        }

        int ret = INF;
        for (int i = 0; i <= m; i++)
            ret = min(ret, dist[n][i]);

        if (ret == INF) cout << "Poor KCM\n";
        else cout << ret << "\n";
    }
}