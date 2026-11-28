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

struct Edge {
    int s, e, c;

    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

int n, m;
int a[10001];
vector<Edge> v;
int parent[10001];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int ret = 1001;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ret = min(ret, a[i]);
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        v.push_back({ s, e, c * 2 + a[s] + a[e] });
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        if (merge(v[i].s, v[i].e)) {
            ret += v[i].c;
            cnt++;
        }

        if (cnt == n - 1) break;
    }

    cout << ret;
}