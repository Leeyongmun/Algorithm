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
ll a[100001];
ll psum[100001];
int L[100001], R[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    stack<int> stk;

    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }

        L[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }

        R[i] = stk.empty() ? n + 1 : stk.top();
        stk.push(i);
    }

    ll mx = -1;
    int retL = 1, retR = 1;

    for (int i = 1; i <= n; i++) {
        int s = L[i] + 1;
        int e = R[i] - 1;

        ll sum = psum[e] - psum[s - 1];
        ll score = sum * a[i];

        if (score > mx) {
            mx = score;
            retL = s;
            retR = e;
        }
    }

    cout << mx << '\n';
    cout << retL << ' ' << retR;
}
