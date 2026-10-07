#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n, q;
vector<int> graph[300001];
int depth[300001];
int parent[20][300001];

void bfs() {
    queue<int> q;

    q.push(1);
    depth[1] = 0;
    parent[0][1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (next == parent[0][cur]) continue;

            parent[0][next] = cur;
            depth[next] = depth[cur] + 1;
            q.push(next);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int diff = depth[a] - depth[b];

    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            a = parent[i][a];
        }
    }

    if (a == b) return a;

    for (int i = 19; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }
}
