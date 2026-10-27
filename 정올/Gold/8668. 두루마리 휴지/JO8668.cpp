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
ll t;
ll a[100001];

bool check(int x) {
    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    priority_queue<ll> pq2;

    ll sum = 0;
    int positive = 0;

    for (int i = 1; i <= min(n, 2 * x); i++) {
        pq2.push(a[i]);

        if (a[i] > 0) positive++;

        int need = max(i - x, min(x, positive));

        while (pq1.size() < need) {
            ll x = pq2.top();
            pq2.pop();

            pq1.push(x);
            sum += x;
        }

        while (!pq1.empty() && !pq2.empty()
            && pq1.top() < pq2.top()) {
            ll small = pq1.top();
            ll large = pq2.top();

            pq1.pop();
            pq2.pop();

            pq1.push(large);
            pq2.push(small);

            sum += large - small;
        }

        if (sum >= t) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    int answer = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer;
}
