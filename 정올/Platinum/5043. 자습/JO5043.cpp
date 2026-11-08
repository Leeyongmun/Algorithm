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
ll m;
vector<ll> a, b;

bool check(ll x) {
    ll balance = 0;
    ll limit = -1LL * n * m;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            ll cnt = (x + a[i] - 1) / a[i];

            if (cnt <= m) {
                balance += m - cnt;
            }
            else {
                ll remain = x - m * a[i];
                ll extra = (remain + b[i] - 1) / b[i];
                balance -= extra;
            }
        }
        else {
            ll cnt = (x + b[i] - 1) / b[i];
            balance += m - cnt;
        }

        if (balance < limit) {
            balance = limit;
        }
    }

    return balance >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    a.resize(n);
    b.resize(n);

    ll mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }

    ll l = 0;
    ll h = 1LL * m * mx;
    ll ret = 0;

    while (l <= h) {
        ll mid = (l + h) / 2;

        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    cout << ret;
}
