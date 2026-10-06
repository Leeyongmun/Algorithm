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
vector<int> tree;
int len = 1;

const int INF = 1e9;

void update(int idx, int val) {
    idx += len;
    tree[idx] = val;
    
    while (idx > 1) {
        idx /= 2;
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

int get(int idx, int s, int e, int ts, int te) {
    if (ts > e || te < s) return -INF;
    else if (s >= ts && e <= te) return tree[idx];
    int mid = (s + e) / 2;
    int l = get(idx * 2, s, mid, ts, te);
    int r = get(idx * 2 + 1, mid + 1, e, ts, te);
    return max(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    while (len < n) len <<= 1;

    tree.assign(len * 2, -INF);

    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k, val;
            cin >> k >> val;
            update(k - 1, val);
        }
        else if (cmd == 2) {
            int s, e;
            cin >> s >> e;
            int x = get(1, 0, len - 1, s - 1, e - 1);
            if (x == -INF) continue;
            cout << x << '\n';
        }
        else {
            int k;
            cin >> k;
            update(k - 1, -INF);
        }
    }
}
