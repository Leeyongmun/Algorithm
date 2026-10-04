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

int n;
int a[201];
vector<int> graph[201];
vector<int> reg[201];
bool visited[201];
vector<int> order;
int scc[201];
int sccCnt = 0;

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

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                graph[i].push_back(j);
                reg[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, false, sizeof(visited));

    reverse(order.begin(), order.end());

    for (int cur : order) {
        if (visited[cur]) continue;

        dfs2(cur);
        sccCnt++;
    }

    vector<int> minCost(sccCnt, 987654321);

    for (int i = 0; i < n; i++) {
        minCost[scc[i]] = min(minCost[scc[i]], a[i]);
    }

    int ret = 0;
    
    for (int i = 0; i < sccCnt; i++) {
        ret += minCost[i];
    }

    cout << ret;
}
