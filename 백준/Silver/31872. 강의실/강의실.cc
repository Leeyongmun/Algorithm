#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, k;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int pre = 0;
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        diff.push_back(v[i] - pre);
        pre = v[i];
    }
    sort(diff.rbegin(), diff.rend());
    int ret = 0;
    for (int i = k; i < n; i++) {
        ret += diff[i];
    }
    cout << ret;
}