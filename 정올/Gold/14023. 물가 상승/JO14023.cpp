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

int n, q;
unordered_map<ll, ll> mp;
ll offset = 0;
ll sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
		sum += x;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		if (s == "INFLATION") {
			int x;
			cin >> x;
			offset += x;
		}
		else {
			int x, y;
			cin >> x >> y;
			if (x != y) {
				ll cnt = mp[x - offset];
				mp[y - offset] += cnt;
				mp[x - offset] = 0;

				sum += cnt * (y - x);
			}
		}
		cout << sum + n * offset << '\n';
	}
}
