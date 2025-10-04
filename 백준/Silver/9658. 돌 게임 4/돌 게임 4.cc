#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0) dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[n] == 0) cout << "CY";
	else cout << "SK";
}