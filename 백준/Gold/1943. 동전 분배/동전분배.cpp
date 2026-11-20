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

int T = 3;
int n;
vector<int> coin;
bool dp[100001];

void init() {
    coin.clear();
    memset(dp, false, sizeof(dp));
}

void devide(int money, int cnt) {
    int k = 1;

    while (cnt > 0) {
        int take = min(k, cnt);
        int value = take * money;

        coin.push_back(value);

        cnt -= take;
        k <<= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (T--) {
        init();
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            devide(a, b);
            sum += (a * b);
        }

        if (sum % 2) {
            cout << 0 << '\n';
            continue;
        }
        int target = sum / 2;

        dp[0] = true;

        for (int i = 0; i < coin.size(); i++) {
            for (int j = target; j >= coin[i]; j--) {
                if (dp[j - coin[i]]) dp[j] = true;
            }
            if (dp[target]) {
                cout << 1 << '\n';
                break;
            }
        }
        if (!dp[target]) cout << 0 << '\n';
    }
}
