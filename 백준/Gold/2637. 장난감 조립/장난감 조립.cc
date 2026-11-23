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

int n, m;
int ind[101];
vector<pair<int, int>> graph[101];
int cnt[101][101];
int check[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        ind[x]++;
        graph[y].push_back({ x, k });
        check[x] = true;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) cnt[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto p : graph[cur]) {
            int next = p.first;
            int c = p.second;

            ind[next]--;
            for (int i = 1; i <= n; i++) {
                cnt[i][next] += cnt[i][cur] * c;
            }

            if (ind[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= n; i++) {
        if(!check[i]) cout << i << " " << cnt[i][n] << '\n';
    }
}