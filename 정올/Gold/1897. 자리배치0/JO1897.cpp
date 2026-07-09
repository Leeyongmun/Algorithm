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

int n, c;
int a[100001];

int main() {
	cin >> n >> c;
	int l = 2000000000;
	int r = -1;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}

	sort(a, a + n);

	int ret = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		int pre = a[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] - pre >= mid) {
				cnt++;
				pre = a[i];
			}
		}
		if (cnt >= c) {
			l = mid + 1;
			ret = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ret;
}
