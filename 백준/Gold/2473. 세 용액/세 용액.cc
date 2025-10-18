#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int n;
vector<int> a;

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	long long mx = 4000000000;
	int ret[3] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long long sum = a[i] + a[j];
			int target = -sum;
			auto it = lower_bound(a.begin() + j + 1, a.end(), target);
			if (it != a.end()) {
				long long tmp = abs((long long)sum + *it);
				if (mx > tmp) {
					mx = tmp;
					ret[0] = a[i];
					ret[1] = a[j];
					ret[2] = *it;
				}
			}
			if (it != a.begin() + j + 1) {
				it--;
				long long tmp = abs((long long)sum + *it);
				if (mx > tmp) {
					mx = tmp;
					ret[0] = a[i];
					ret[1] = a[j];
					ret[2] = *it;
				}
			}
		}
	}
	cout << ret[0] << ' ' << ret[1] << ' ' << ret[2];
}