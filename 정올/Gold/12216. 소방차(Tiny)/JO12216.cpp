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

const int INF = 1e9;

int p, f;
int pump[21], fire[21];
int dp[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> f;

    for (int i = 1; i <= p; i++) {
        cin >> pump[i];
    }

    for (int i = 1; i <= f; i++) {
        cin >> fire[i];
    }

    for (int i = 0; i <= p; i++) {
        fill(dp[i], dp[i] + 21, INF);
        dp[i][0] = 0;
    }

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= min(i, f); j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(pump[i] - fire[j]));
        }
    }

    cout << dp[p][f];
}
