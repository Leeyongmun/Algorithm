#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long n, m;
		cin >> n >> m;
		long long cnt = 0;
		while (n > 0) {
			cnt++;
			n >>= 1;
		}
		cout << cnt + m << '\n';
	}
}