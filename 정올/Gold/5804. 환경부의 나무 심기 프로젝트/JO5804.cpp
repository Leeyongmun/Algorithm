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

int n, k;
vector<int> v;
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	v.resize(n);

	int l = 1;
	int r = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		r = max(r, v[i]);
	}

	sort(v.begin(), v.end());

	while (l <= r) {
		int mid = (l + r) / 2;
		
		int cnt = 1;
		int prev = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] - prev >= mid) {
				prev = v[i];
				cnt++;
			}
		}

		if (cnt >= k) {
			ret = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ret;
}
