#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
using namespace std;

int n, m;
int p[100001], c[100001];
int dp[5001];
bool take[5001][5001];

const int INF = 1e9;

int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
	}

	fill(dp, dp + 5001, -INF);

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= c[i]; j--) {
			if (dp[j - c[i]] == -INF) continue;
			if (dp[j] < dp[j - c[i]] + p[i]) {
				dp[j] = dp[j - c[i]] + p[i];
				take[i][j] = true;
			}
		}
	}

	int best = -1;

	for (int i = 1; i <= m; i++) {
		if (dp[i] == -INF) continue;
		if (best == -1 || dp[i] > dp[best]) {
			best = i;
		}
	}

	if (best == -1) {
		cout << -1;
		return 0;
	}

	vector<int> path;
	int cur = best;

	for (int i = n; i >= 1; i--) {
		if (take[i][cur]) {
			path.push_back(i);
			cur -= c[i];
		}
	}

	reverse(path.begin(), path.end());

	cout << path.size() << '\n';

	for (int x : path) {
		cout << x << ' ';
	}
}
