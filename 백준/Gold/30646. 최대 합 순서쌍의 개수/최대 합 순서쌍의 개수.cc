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

int n;
ll a[200001];
ll psum[200001];
ll mx = -1;
ll cnt = 0;
unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!mp.count(a[i])) {
            mp[a[i]] = i;
            if (a[i] > mx) {
                mx = a[i];
                cnt = 1;
            }
            else if (a[i] == mx) {
                cnt++;
            }
        }
        else {
            ll sum = psum[i] - psum[mp[a[i]] - 1];
            if (sum > mx) {
                mx = sum;
                cnt = 1;
            }
            else if (sum == mx) {
                cnt++;
            }
        }
    }

    cout << mx << ' ' << cnt;
}