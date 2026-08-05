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

int n;
vector<pair<int, int>> v;
int dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	dp[0] = v[0].second;
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (v[i].second > dp[idx]) {
			dp[++idx] = v[i].second;
		}
		else {
			int x = lower_bound(dp, dp + idx + 1, v[i].second) - dp;
			dp[x] = v[i].second;
		}
	}

	cout << n - idx - 1;
}
