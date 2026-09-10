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

int n, m, t;
int s[200001], e[200001];
int diff[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> e[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		int l = max(s[a], s[b]);
		int r = min(e[a], e[b]);

		if (l < r) {
			diff[l]++;
			diff[r]--;
		}
	}

	int ret = 0;

	for (int i = 0; i < t; i++) {
		ret += diff[i];
		cout << ret << '\n';
	}
}
