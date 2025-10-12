#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	for (int i = 4; i <= n; i++) {
		dp[i] = !dp[i - 3] || !dp[i - 1];
	}
	cout << (dp[n] ? "SK" : "CY");
}