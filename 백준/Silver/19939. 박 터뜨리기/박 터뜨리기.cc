#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	v.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		v[i] = i;
		n -= i;
	}
	if (n < 0) {
		cout << -1;
		return 0;
	}
	while (n > 0) {
		for (int i = k; i >= 1 && n > 0; i--) {
			v[i]++;
			n--;
		}
	}
	cout << v[k] - v[1];
}