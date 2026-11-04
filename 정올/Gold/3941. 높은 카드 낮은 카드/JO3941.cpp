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
vector<int> a, b;
vector<bool> check;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    check.resize(n * 2 + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        check[a[i]] = true;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (check[i]) continue;
        b.push_back(i);
    }

    sort(a.begin(), a.begin() + n / 2);
    sort(a.begin() + n / 2, a.end());
    sort(b.begin(), b.end());

    int ret = 0;

    int i = 0;
    int j = n / 2;

    while (i < n / 2 && j < n) {
        if (b[j] > a[i]) {
            ret++;
            i++;
            j++;
        }
        else j++;
    }

    i = n - 1;
    j = n / 2 - 1;

    while (j >= 0 && i >= n / 2) {
        if (b[j] < a[i]) {
            ret++;
            j--;
            i--;
        }
        else j--;
    }

    cout << ret;
}
