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

struct Cow {
    int r, a, t;

    bool operator < (const Cow& other) const {
        return r > other.r;
    }
};

int n;
vector<Cow> cows;
priority_queue<Cow> pq;

bool cmp(const Cow& x, const Cow& y) {
    return x.a < y.a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cows.resize(n);

    for (int i = 0; i < n; i++) {
        cows[i].r = i;
        cin >> cows[i].a >> cows[i].t;
    }

    sort(cows.begin(), cows.end(), cmp);

    int cur = 0;
    int ret = 0;
    int idx = 0;

    while (idx < n || !pq.empty()) {
        if (pq.empty() && idx < n) {
            cur = max(cur, cows[idx].a);
        }

        while (idx < n && cows[idx].a <= cur) {
            pq.push(cows[idx]);
            idx++;
        }

        Cow now = pq.top();
        pq.pop();

        ret = max(ret, cur - now.a);
        cur += now.t;
    }

    cout << ret;
}
