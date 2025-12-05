#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int n, l;
int x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l;
	while (l <= 100) {
		if (l % 2 == 0) {
			if (n % l == l / 2) {
				x = (n / l) - (l / 2) + 1;
				if (x < 0) {
					l++;
					continue;
				}
				break;
			}
		}
		else {
			if (n % l == 0) {
				x = n / l - (l / 2);
				if (x < 0) {
					l++;
					continue;
				}
				break;
			}
		}
		l++;
	}
	if (l > 100) cout << -1;
	else {
		for (int i = x; i < x + l; i++) {
			cout << i << ' ';
		}
	}
}