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

string s;
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    int n = s.size();

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;

            if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c')) {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            }

            for (int k = l; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }

    cout << dp[0][n - 1];
}
