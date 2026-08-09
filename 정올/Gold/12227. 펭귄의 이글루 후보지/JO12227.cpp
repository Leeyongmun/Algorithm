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

int n, k;
int a[300001];
ll leftDp[300001];
ll rightDp[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	leftDp[1] = a[1];

	for (int i = 2; i <= n; i++) {
		leftDp[i] = max((ll)a[i], leftDp[i - 1] + a[i]);
	}

	rightDp[n] = a[n];

	for (int i = n - 1; i >= 1; i--) {
		rightDp[i] = max((ll)a[i], rightDp[i + 1] + a[i]);
	}

	for (int i = 1; i <= n; i++) {
		ll best = leftDp[i] + rightDp[i] - a[i];

		if (best >= k) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}
