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
#include<climits>
using namespace std;
using ll = long long;

int n, r;
vector<pair<int, int>> graph[1001];

void init() {
    for (int i = 0; i <= 1000; i++) {
        graph[i].clear();
    }
}

int dfs(int cur, int parent) {
    int sum = 0;
    bool isLeaf = true;

    for (auto p : graph[cur]) {
        int next = p.first;
        if (next == parent) continue;
        isLeaf = false;
        int cost = dfs(next, cur);
        sum += min(p.second, cost);
    }

    if (isLeaf) return 1e9;

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n >> r;
        if (n == 0 && r == 0) break;

        init();

        for (int i = 0; i < n - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            graph[a].push_back({ b, c });
            graph[b].push_back({ a, c });
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        cout << dfs(r, 0) << '\n';
    }
}
