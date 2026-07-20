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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	ll x;
	cin >> x;

	ll mx = x, maxSum = x;
	ll mn = x, minSum = x;
	ll total = x;

	for (int i = 1; i < n; i++) {
		cin >> x;

		total += x;

		mx = max(x, mx + x);
		maxSum = max(maxSum, mx);

		mn = min(x, mn + x);
		minSum = min(minSum, mn);
	}

	if (maxSum < 0) cout << maxSum;
	else cout << max(maxSum, total - minSum);
}
