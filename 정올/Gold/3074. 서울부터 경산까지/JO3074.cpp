#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n, k;
vector<int> dp;
vector<int> ndp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	dp.assign(k + 1, -1);
	ndp.resize(k + 1);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		int at, bt, aw, bw;
		cin >> at >> aw >> bt >> bw;

		fill(ndp.begin(), ndp.end(), -1);
		for (int t = 0; t <= k; t++) {
			if (dp[t] == -1) continue;
			if (t + at <= k) {
				ndp[t + at] = max(ndp[t + at], dp[t] + aw);
			}

			if (t + bt <= k) {
				ndp[t + bt] = max(ndp[t + bt], dp[t] + bw);
			}
		}

		dp.swap(ndp);
	}

	cout << *max_element(dp.begin(), dp.end());
}
