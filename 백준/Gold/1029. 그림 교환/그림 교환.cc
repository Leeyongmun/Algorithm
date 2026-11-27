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

int n;
int a[16][16];
int dp[1 << 16][16][10];
int ret = 1;

int dfs(int mask, int cur, int cost) {
    if (dp[mask][cur][cost] != -1) return dp[mask][cur][cost];
    dp[mask][cur][cost] = 1;

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        if (cost > a[cur][i]) continue;
        dp[mask][cur][cost] = max(dp[mask][cur][cost], dfs(mask | (1 << i), i, a[cur][i]) + 1);
    }

    return dp[mask][cur][cost];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 0, 0);
}