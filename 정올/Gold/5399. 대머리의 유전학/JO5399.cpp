#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> graph[100001];
int dp[100001][2];

void dfs(int cur){
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for(int next : graph[cur]){
        dfs(next);

        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];    
    }
}

int main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        graph[x].push_back(i);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]);
}
