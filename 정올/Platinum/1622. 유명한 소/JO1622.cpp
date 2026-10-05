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

int n, m;
vector<int> graph[10001];
vector<int> reg[10001];
int visited[10001];
vector<int> order;
int sccCnt = 0;
int scc[10001];
int outd[10001];

void dfs1(int cur) {
    visited[cur] = true;

    for (int next : graph[cur]) {
        if (visited[next]) continue;
        dfs1(next);
    }

    order.push_back(cur);
}

void dfs2(int cur) {
    visited[cur] = true;
    scc[cur] = sccCnt;

    for (int next : reg[cur]) {
        if (visited[next]) continue;
        dfs2(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reg[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs1(i);
    }

    memset(visited, false, sizeof(visited));

    reverse(order.begin(), order.end());

    for (int x : order) {
        if (visited[x]) continue;
        dfs2(x);
        sccCnt++;
    }

    for (int i = 1; i <= n; i++) {
        for (int x : graph[i]) {
            if (scc[i] == scc[x]) continue;
            outd[scc[i]]++;
        }
    }

    int cnt = 0;
    int idx = -1;

    for (int i = 0; i < sccCnt; i++) {
        if (outd[i] == 0) {
            idx = i;
            cnt++;
        }
        if (cnt > 1) {
            cout << 0;
            return 0;
        }
    }

    int ret = 0;

    for (int i = 1; i <= n; i++) {
        if (idx == scc[i]) ret++;
    }

    cout << ret;
}
