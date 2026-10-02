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

int n, m, k, s, e;
vector<pair<int, ll>> graph[100001];
vector<pair<int, ll>> reg[100001];
ll dp[11][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> s >> e;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({ b, t });
        reg[b].push_back({ a, t });
    }

    const ll NEG = -(1LL << 60);

    fill(&dp[0][0], &dp[0][0] + 11 * 100001, NEG);

    dp[0][s] = 0;

    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == NEG) continue;

            for (auto p : graph[j]) {
                dp[i][p.first] = max(dp[i][p.first], dp[i][j] + p.second);
            }

            if (i < k) {
                for (auto p : reg[j]) {
                    dp[i + 1][p.first] = max(dp[i + 1][p.first], dp[i][j]);
                }
            }
        }
    }

    ll ret = NEG;

    for (int i = 0; i <= k; i++) {
        ret = max(ret, dp[i][e]);
    }

    if (ret == NEG) cout << -1;
    else cout << ret;
}
