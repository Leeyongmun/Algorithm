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

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	v.push_back(0);

	vector<int> sum1;

	for (int i = 0; i < n + 1; i++) {
		for (int j = i; j < n + 1; j++) {
			sum1.push_back(v[i] + v[j]);
		}
	}

	sort(sum1.begin(), sum1.end());

	int ret = 0;

	int l = 0;
	int r = sum1.size() - 1;

	while (l <= r) {
		int sum = sum1[l] + sum1[r];
		if (sum <= m) {
			ret = max(ret, sum);
			l++;
		}
		else {
			r--;
		}
	}

	cout << ret;
}
