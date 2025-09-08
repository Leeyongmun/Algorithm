#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n, k;
int w[1001], t[1001];
vector<int> dp;

int main() {
	cin >> n >> k;
	dp.resize(10001);
	for (int i = 1; i <= k; i++) {
		cin >> w[i] >> t[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= t[i]; j--) {
			dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}