#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int l = 1;
	int r = 0;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		r = max(r, num);
	}

	int ret = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += v[i] / mid;
		}
		if (sum >= n) {
			l = mid + 1;
			ret = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ret;
}