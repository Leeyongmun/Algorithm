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

int n, q;
int len = 1;
int a[1000001];
vector<int> mx_tree, mn_tree;
const int INF = 1e9;

int get_max(int idx, int s, int e, int ts, int te) {
    if (s > te || e < ts) return -1;
    else if (s >= ts && e <= te) return mx_tree[idx];
    int mid = (s + e) / 2;
    int l = get_max(idx * 2, s, mid, ts, te);
    int r = get_max(idx * 2 + 1, mid + 1, e, ts, te);
    return max(l, r);
}

int get_min(int idx, int s, int e, int ts, int te) {
    if (s > te || e < ts) return INF;
    else if (s >= ts && e <= te) return mn_tree[idx];
    int mid = (s + e) / 2;
    int l = get_min(idx * 2, s, mid, ts, te);
    int r = get_min(idx * 2 + 1, mid + 1, e, ts, te);
    return min(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    while (len < n) {
        len <<= 1;
    }

    mx_tree.assign(len * 2, -1);
    mn_tree.assign(len * 2, INF);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx_tree[len + i] = a[i];
        mn_tree[len + i] = a[i];
    }

    for (int i = len - 1; i > 0; i--) {
        if (mx_tree[i * 2] > mx_tree[i * 2 + 1]) mx_tree[i] = mx_tree[i * 2];
        else mx_tree[i] = mx_tree[i * 2 + 1];

        if (mn_tree[i * 2] < mn_tree[i * 2 + 1]) mn_tree[i] = mn_tree[i * 2];
        else mn_tree[i] = mn_tree[i * 2 + 1];
    }

    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;

        cout << get_max(1, 0, len - 1, s - 1, e - 1) - get_min(1, 0, len - 1, s - 1, e - 1) << '\n';
    }
}
