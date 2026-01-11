#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
char a[1001];
int dp[1001][501];
int m, k;
vector<pair<int, char>> graph[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m >> k;
	for (int i = 0; i < k; i++) {
		int from, to;
		char c;
		cin >> from >> to >> c;
		graph[from].push_back({ to, c });
		graph[to].push_back({ from, c });
	}
	fill(&dp[0][0], &dp[0][0] + 1001 * 501, -987654321);
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (auto p : graph[j]) {
				int next = p.first;
				char c = p.second;
				if (a[i] == c) dp[i][next] = max(dp[i - 1][j] + 10, dp[i][next]);
				else dp[i][next] = max(dp[i][next], dp[i - 1][j]);
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= m; i++) {
		mx = max(mx, dp[n][i]);
	}
	cout << mx;
}