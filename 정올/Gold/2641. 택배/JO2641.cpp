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

struct State {
    int s, e, w;
};

int n, c;
int m;
int load[2001];
vector<State> v;

bool cmp(State& a, State& b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c >> m;

    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v.push_back({ s, e, w });
    }

    sort(v.begin(), v.end(), cmp);

    int ret = 0;

    for (State& p : v) {
        int s = p.s;
        int e = p.e;
        int w = p.w;
        int mx = 0;

        for (int i = s; i < e; i++) {
            mx = max(mx, load[i]);
        }

        int plus = min(w, c - mx);

        for (int i = s; i < e; i++) {
            load[i] += plus;
        }

        ret += plus;
    }

    cout << ret;
}
