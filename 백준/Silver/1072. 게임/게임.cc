#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
#include<deque>
#include<unordered_map>
using namespace std;

int x, y;

int main() {
	cin >> x >> y;
	long long z = (long long)y * 100 / x;

	if (z == 100) {
		cout << -1;
		return 0;
	}

	int l = 1;
	int r = 1000000000;

	int ret = -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		long long nz = (long long)(y + mid) * 100 / (x + mid);
		if (nz > z) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
	
}