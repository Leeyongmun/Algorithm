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

int n;
bool check[1 << 18];
int a[19];
int ret[19];

int countBit(int mask) {
	int cnt = 0;

	while (mask) {
		mask &= (mask - 1);
		cnt++;
	}
	
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				a[i] |= (1 << j);
			}
		}
	}

	check[0] = true;

	for (int mask = 1; mask < (1 << n); mask++) {
		int cnt = countBit(mask);

		int cur = 0;

		while (!(mask & (1 << cur))) {
			cur++;
		}

		int prev = mask ^ (1 << cur);

		if (check[prev] && (a[cur] & prev) == prev) {
			check[mask] = true;
			ret[cnt]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ret[i];
		if (i == n) break;
		cout << ", ";
	}
}
