#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n, m;
int a[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long l = 1;
	long long r = 1000000000000;

	long long ret = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / a[i];
		}
		if (cnt >= m) {
			r = mid - 1;
			ret = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
}