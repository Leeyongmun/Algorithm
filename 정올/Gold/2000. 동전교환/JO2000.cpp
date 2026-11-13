#include<iostream>
using namespace std;

int n;
int money[11];
int g;
int dp[64001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> money[i];
    }
    cin >> g;

    fill(dp, dp + 64001, 987654321);

    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = money[i]; j <= g; j++){
            dp[j] = min(dp[j], dp[j - money[i]] + 1);
        }
    }

    if(dp[g] != 987654321) cout << dp[g];
    else cout << "impossible";
}
