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

int n, m, k;
int color[300001];
int dp[300001][32];
vector<int> graph[300001];

int bitCount(int mask) {
    int cnt = 0;

    while (mask != 0) {
        mask = mask & (mask - 1);
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        color[i]--;

        dp[i][1 << color[i]] = 1;
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int limit = 1 << k;
    ll ret = 0;

    for (int mask = 1; mask < limit; mask++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][mask] == 0) continue;

            for (int next : graph[i]) {
                if (mask & (1 << color[next])) continue;

                int nmask = mask | (1 << color[next]);
                dp[next][nmask] += dp[i][mask];
            }
        }
    }

    for (int mask = 1; mask < limit; mask++) {
        if (bitCount(mask) < 2) continue;

        for (int i = 1; i <= n; i++) {
            ret += dp[i][mask];
        }
    }

    cout << ret;
}
