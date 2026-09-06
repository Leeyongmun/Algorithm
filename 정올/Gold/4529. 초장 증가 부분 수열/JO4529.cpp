#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[500001];
int dp[500001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    dp[0] = a[0];
    int idx = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] > dp[idx]){
            dp[++idx] = a[i];
        }
        else{
            int x = lower_bound(dp, dp + idx + 1, a[i]) - dp;
            dp[x] = a[i];
        }
    }

    cout << idx + 1;
}
