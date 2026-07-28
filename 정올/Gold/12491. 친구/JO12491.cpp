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

int n, k1, k2;
int x[500001];
int school[500001];

vector<int> all;
vector<vector<int>> sc;

int countRange(const vector<int>& v, int x, int k) {
	auto left = lower_bound(v.begin(), v.end(), x - k);
	auto right = upper_bound(v.begin(), v.end(), x + k);

	return right - left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k1 >> k2;

	sc.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> school[i];
		all.push_back(x[i]);
		sc[school[i]].push_back(x[i]);
	}

	sort(all.begin(), all.end());
	for (int i = 1; i <= n; i++) {
		sort(sc[i].begin(), sc[i].end());
	}

	for (int i = 1; i <= n; i++) {
		int a = countRange(all, x[i], k2);

		int b = countRange(sc[school[i]], x[i], k2);
		int c = countRange(sc[school[i]], x[i], k1);

		int ret = a - b + c - 1;

		cout << ret << ' ';
	}
}
