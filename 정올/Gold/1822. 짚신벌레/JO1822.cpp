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

int a, b, d, n;
int birth[1000001];
int diff[1000001];
const int MOD = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> d >> n;

    diff[0] = 1;
    diff[1] = -1;

    int cnt = 0;
    int alive = 0;

    for (int i = 0; i <= n; i++) {
        cnt = (cnt + diff[i] + MOD) % MOD;
        birth[i] = cnt;

        alive = (alive + cnt) % MOD;

        if (i >= d) {
            alive = (alive - birth[i - d] + MOD) % MOD;
        }

        if (i + a <= n) {
            diff[i + a] = (diff[i + a] + cnt) % MOD;
        }

        if (i + b <= n) {
            diff[i + b] = (diff[i + b] - cnt + MOD) % MOD;
        }
    }

    cout << alive;
}
