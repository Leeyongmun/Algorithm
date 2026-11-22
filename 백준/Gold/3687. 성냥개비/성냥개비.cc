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

int T;
int n;
int digit[] = { 0, 0, 1, 7, 4, 2, 0, 8};
ll dp[101];
const ll INF = (1LL << 60);

void init() {
    fill(dp, dp + 101, INF);

    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;

    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            if (dp[i - j] == INF) continue;

            dp[i] = min(dp[i], dp[i - j] * 10 + digit[j]);
        }
    }
}

string getMax(int n) {
    string ret = "";

    if (n % 2 == 1) {
        ret += '7';
        n -= 3;
    }

    while (n > 0) {
        ret += '1';
        n -= 2;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    cin >> T;

    while (T--) {
        cin >> n;

        cout << dp[n] << " " << getMax(n) << '\n';
    }
}