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

int T;
int n, k;
char a[51][51];
int dp[51][51][2][4];
int dy[] = { 1, 0 };
int dx[] = { 0, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, 0, sizeof(dp));

        if (a[0][1] == '.') dp[0][1][1][0] = 1;
        if (a[1][0] == '.') dp[1][0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'H') continue;

                for (int d = 0; d < 2; d++) {
                    for (int c = 0; c <= k; c++) {
                        if (dp[i][j][d][c] == 0) continue;

                        for (int l = 0; l < 2; l++) {
                            int ny = i + dy[l];
                            int nx = j + dx[l];

                            if (ny >= n || nx >= n) continue;
                            if (a[ny][nx] == 'H') continue;

                            if (d == l) dp[ny][nx][l][c] += dp[i][j][d][c];
                            else if (c < k) {
                                dp[ny][nx][l][c + 1] += dp[i][j][d][c];
                            }
                        }
                    }
                }
            }
        }

        int ret = 0;

        for (int i = 0; i <= k; i++) {
            ret += dp[n - 1][n - 1][0][i];
            ret += dp[n - 1][n - 1][1][i];
        }

        cout << ret << '\n';
    }
}
