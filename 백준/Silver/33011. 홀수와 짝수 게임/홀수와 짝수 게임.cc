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

int T, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		int odd = 0, even = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num % 2) odd++;
			else even++;
		}
		if (even == odd) cout << "heeda0528\n";
		else {
			if (even > odd) {
				if (even % 2) {
					cout << "amsminn\n";
				}
				else {
					cout << "heeda0528\n";
				}
			}
			else {
				if (odd % 2) {
					cout << "amsminn\n";
				}
				else {
					cout << "heeda0528\n";
				}
			}
		}
	}
}