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
using ll = long long;

int d, n;
int a[101], b[101];
ll dp[102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d >> n;

	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	fill(dp, dp + 102, (1LL << 60));
	vector<int> pre(n + 2, -1);

	dp[0] = 0;

	for (int i = 1; i <= n + 1; i++) {
		ll dist = 0;

		for (int j = i - 1; j >= 0; j--) {
			dist += a[j];
			
			if (dist > d) break;

			ll cost = dp[j];

			if (i <= n) cost += b[i];
			if (cost < dp[i]) {
				dp[i] = cost;
				pre[i] = j;
			}
		}
	}

	cout << dp[n + 1] << '\n';

	if (dp[n + 1] == 0) return 0;

	vector<int> path;

	int cur = pre[n + 1];

	while (cur != 0) {
		path.push_back(cur);
		cur = pre[cur];
	}

	cout << path.size() << '\n';

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
}
