#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n;
vector<int> v;
vector<int> dp;

int main() {
	cin >> n;
	v.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int idx = 0;
	int cnt = 1;
	dp[0] = v[0];

	for (int i = 1; i < n; i++) {
		if (v[i] > dp[idx]) {
			dp[++idx] = v[i];
			cnt++;
		}
		else {
			int tmp = int(lower_bound(dp.begin(), dp.begin() + idx + 1, v[i]) - dp.begin());
			dp[tmp] = v[i];
		}
	}

	cout << cnt;
}