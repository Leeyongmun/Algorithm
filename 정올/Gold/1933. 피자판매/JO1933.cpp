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

int k;
int n, m;
int a[1001], b[1001];
unordered_map<int, int> mp1, mp2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n >> m;
    
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    mp1[total]++;
    mp1[0]++;
    total = 0;

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        total += b[i];
    }
    mp2[total]++;
    mp2[0]++;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < n; j++) {
            sum += a[(i + j - 1) % n];
            mp1[sum]++;
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 1; j < m; j++) {
            sum += b[(i + j - 1) % m];
            mp2[sum]++;
        }
    }

    ll ret = 0;

    for (int i = 0; i <= k; i++) {
        ret += 1LL * mp1[i] * mp2[k - i];
    }

    cout << ret;
}
