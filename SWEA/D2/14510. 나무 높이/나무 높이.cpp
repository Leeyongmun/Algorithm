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

int T;
int n;


int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		vector<int> tree(n);
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> tree[i];
			mx = max(mx, tree[i]);
		}
		int odd = 0;
		int even = 0;
		for (int i = 0; i < n; i++) {
			even += (mx - tree[i]) / 2;
			odd += (mx - tree[i]) % 2;
		}
		if (odd < even) {
			while (abs(odd - even) > 1) {
				odd += 2;
				even--;
			}
		}
		int ret = 0;
		if (odd > even) {
			ret = odd * 2 - 1;
		}
		else {
			ret = even * 2;
		}
		cout << "#" << t << " " << ret << '\n';
	}
}