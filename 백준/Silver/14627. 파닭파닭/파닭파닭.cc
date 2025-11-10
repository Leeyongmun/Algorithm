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
int a[1000001];
long long sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int l = 1;
	int r = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r = max(r, a[i]);
		sum += a[i];
	}
	long long ret = 0;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += a[i] / mid;
		}
		if (cnt >= m) {
			ret = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << sum - ret * m;
	
}