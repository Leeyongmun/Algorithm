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

int n;
vector<int> a;
vector<int> tree;

void update(int idx, int val) {
    while (idx <= n) {
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;

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

    a.resize(n);
    tree.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    ll ret = 0;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;

        ret += i - query(idx);
        update(idx, 1);
    }

    cout << ret;
}
