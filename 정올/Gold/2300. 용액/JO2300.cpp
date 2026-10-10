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
int a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0;
    int r = n - 1;
    int ret = 2000000002;
    int v1, v2;

    while (l < r) {
        int sum = a[l] + a[r];
        if (ret > abs(sum)) {
            ret = abs(sum);
            v1 = a[l];
            v2 = a[r];
        }
        if (sum > 0) {
            r--;
        }
        else {
            l++;
        }
    }

    cout << v1 << ' ' << v2;
}
