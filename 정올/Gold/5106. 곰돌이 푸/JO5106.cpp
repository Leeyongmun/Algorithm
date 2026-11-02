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
int a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<ll> stk;
    int ret = 0;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top() > a[i]) {
            stk.pop();
        }

        if (a[i] == 0) continue;

        if (stk.empty() || stk.top() < a[i]) {
            stk.push(a[i]);
            ret++;
        }
    }

    cout << ret;
}
