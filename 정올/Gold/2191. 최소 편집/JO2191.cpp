#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
string a, b;
int dp[1001][1001];

int main(){

    cin >> n >> a;
    cin >> m >> b;

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }

    for(int i = 0; i <= m; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;

            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost));
        }
    }

    cout << dp[n][m];
    
}
