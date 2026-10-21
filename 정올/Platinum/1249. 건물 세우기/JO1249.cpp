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

int n;
int cost[21][21];
int dp[1 << 20];
int choice[1 << 20];
const int INF = 987654321;

int dfs(int cur, int mask) {
    if (cur == n) return 0;
    if (dp[mask] != INF) return dp[mask];

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        int nmask = mask | (1 << i);
        int val = cost[cur][i] + dfs(cur + 1, nmask);

        if (val < dp[mask]) {
            dp[mask] = val;
            choice[mask] = i;
        }
    }

    return dp[mask];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    fill(dp, dp + (1 << 20), INF);

    cout << dfs(0, 0) << '\n';

    int mask = 0;
    for (int i = 0; i < n; i++) {
        int check = choice[mask];
        cout << check + 1 << ' ';
        mask |= (1 << check);
    }
}
