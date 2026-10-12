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

const int INF = 1e9;

int n, l;
int h[1001], w[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
    }

    fill(dp, dp + n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int width = 0;
        int height = 0;

        for (int j = i; j >= 1; j--) {
            width += w[j];
            height = max(height, h[j]);

            if (width > l) break;

            dp[i] = min(dp[i], dp[j - 1] + height);
        }
    }

    cout << dp[n];;
}
