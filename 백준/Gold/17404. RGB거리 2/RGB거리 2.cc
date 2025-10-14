#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<map>
#include<unordered_set>
using namespace std;

int n;
int a[1001][3];
int dp[1001][3][3];
int ret = 987654321;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	for (int start = 0; start < 3; start++) {
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j][start] = 987654321;
			}
		}
		dp[1][start][start] = a[1][start];

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j][start] = min(dp[i - 1][(j + 1) % 3][start], dp[i - 1][(j + 2) % 3][start]) + a[i][j];
			}
		}

		for (int i = 0; i < 3; i++) {
			if (i == start) continue;
			ret = min(ret, dp[n][i][start]);
		}
	}
	cout << ret;
}