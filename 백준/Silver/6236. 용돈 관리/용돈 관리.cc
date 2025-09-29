#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> v;

bool check(int x) {
	int cnt = 0;
	int money = 0;
	for (int i = 0; i < v.size(); i++) {
		if (money < v[i]) {
			money = x;
			cnt++;
		}
		money -= v[i];
	}
	return cnt <= m;
}

int main() {
	cin >> n >> m;
	v.resize(n);
	int r = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		r += v[i];
	}
	int l = *max_element(v.begin(), v.end());

	int ret = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
}