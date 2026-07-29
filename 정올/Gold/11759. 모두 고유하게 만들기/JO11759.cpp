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
using ll = long long;

int T;
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> k;
		unordered_map<ll, vector<ll>> mp;
		int d = abs(k);
		
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			int r = x % d;
			mp[r].push_back(x);
		}

		ll ret = 0;

		for (auto& p : mp) {
			auto& v = p.second;

			if (k > 0) {
				sort(v.begin(), v.end());
				ll last = -(1LL << 60);

				for (ll x : v) {
					if (x > last) {
						last = x;
					}
					else {
						ll need = (last - x) / d + 1;
						ret += need;
						last = x + need * d;
					}
				}
			}
			else {
				sort(v.rbegin(), v.rend());
				ll last = (1LL << 60);

				for (ll x : v) {
					if (x < last) {
						last = x;
					}
					else {
						ll need = (x - last) / d + 1;
						ret += need;
						last = x - need * d;
					}
				}
			}
		}
		cout << ret << '\n';
	}
}
