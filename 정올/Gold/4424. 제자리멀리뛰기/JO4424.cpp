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

int d, n, m;
int a[50001];
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> d >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int l = 1;
	int r = d;

	while (l <= r) {
		int mid = (l + r) / 2;

		int cur = 0;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] - cur < mid) {
				cnt++;
			}
			else {
				cur = a[i];
			}
		}

		if (d - cur < mid) {
			cnt++;
		}

		if (cnt <= m) {
			l = mid + 1;
			ret = mid;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ret;
}
