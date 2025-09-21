#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> v;

int main() {
	cin >> n;
	v.resize(n);
	int r = -1;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		r = max(r, v[i]);
	}
	
	cin >> m;

	int l = 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) sum += mid;
			else sum += v[i];
		}
		if (sum > m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r;
}