#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
string a, b;
vector<vector<int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> a >> b;

    dp.assign(n + 1, vector<int>(m + 1, 987654321));

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j < m) {
                dp[i + 1][j + 1] = min(dp[i][j] + (a[i] != b[j]), dp[i + 1][j + 1]);
            }
        }
    }

    cout << dp[n][m];
}
