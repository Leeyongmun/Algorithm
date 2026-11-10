#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
using ll = long long;
int n;
int h[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    ll ret = 0;
    stack<int> stk;

    for(int i = 0; i <= n; i++){
        ll cur = (i == n ? 0 : h[i]);

        while(!stk.empty() && h[stk.top()] > cur){
            ll height = h[stk.top()];
            stk.pop();

            ll width = stk.empty() ? i : i - stk.top() - 1;

            ret = max(ret, height * width);
        }

        if(i < n) stk.push(i);
    }

    cout << ret;
}
