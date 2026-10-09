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
int a[80001];
int mx[80001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<pair<int,int>> stk;

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top().second < a[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            mx[i] = n;
        }

        else {
            mx[i] = stk.top().first;
        }

        stk.push({ i, a[i] });
    }

    ll ret = 0;
    
    for (int i = 0; i < n; i++) {
        ret += mx[i] - i - 1;
    }

    cout << ret;
}
