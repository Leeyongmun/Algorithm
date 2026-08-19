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
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n, m;
int a[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<bool> dp0(m, false);
	vector<bool> dp1(m, false);

	dp0[0] = true;

	for (int i = 0; i < n; i++) {
		int cur = a[i];

		vector<bool> ndp0(m, false);
		vector<bool> ndp1(m, false);

		for (int j = 0; j < m; j++) {
			if (dp0[j] || dp1[j]) {
				ndp0[j] = true;
			}

			if (dp0[j]) {
				ndp1[(j + cur) % m] = true;
			}
		}

		dp0 = move(ndp0);
		dp1 = move(ndp1);
	}

	for (int i = m - 1; i >= 0; i--) {
		if (dp0[i] || dp1[i]) {
			cout << i;
			break;
		}
	}
}
