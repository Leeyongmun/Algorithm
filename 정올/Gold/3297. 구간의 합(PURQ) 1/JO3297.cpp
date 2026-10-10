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

int n, m;
vector<ll> tree;
vector<int> a;

void update(int idx, ll val) {
    while (idx <= n) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

ll query(int idx) {
    ll sum = 0;

    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & -idx;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    tree.resize(n + 1);
    a.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int idx, nd;
            cin >> idx >> nd;

            ll diff = nd - a[idx];
            a[idx] = nd;

            update(idx, diff);
        }
        else {
            int st, ed;
            cin >> st >> ed;

            cout << query(ed) - query(st - 1) << '\n';
        }
    }
}
