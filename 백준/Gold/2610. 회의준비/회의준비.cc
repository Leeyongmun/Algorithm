#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
#include<climits>
#include<cstring>
using namespace std;
using ll = long long;

const int INF = 1e9;

int n, m;
int parent[101];
int graph[101][101];
int mn[101], president[101];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int cnt = n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        mn[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (merge(a, b)) {
            cnt--;
        }
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        int idx = find(i);
        for (int j = 1; j <= n; j++) {
            if (idx == find(j)) {
                mx = max(mx, graph[i][j]);
            }
        }

        if (mn[idx] > mx) {
            mn[idx] = mx;
            president[idx] = i;
        }
    }

    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (president[i] != 0) ret.push_back(president[i]);
    }

    sort(ret.begin(), ret.end());

    cout << cnt << '\n';

    for (int x : ret) {
        cout << x << '\n';
    }
}