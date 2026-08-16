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
#include <cctype>
using namespace std;
using ll = long long;

int T;
int x, y;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> x >> y >> s;

		const ll INF = (1LL << 60);

		ll c = INF;
		ll j = INF;

		if (s[0] == 'C' || s[0] == '?') c = 0;
		if (s[0] == 'J' || s[0] == '?') j = 0;

		for (int i = 1; i < s.size(); i++) {
			char ch = s[i];

			ll nc = INF;
			ll nj = INF;

			if (ch == 'C' || ch == '?') {
				nc = min(c, j + y);
			}
			
			if (ch == 'J' || ch == '?') {
				nj = min(j, c + x);
			}

			c = nc;
			j = nj;
		}

		cout << "Case #" << t << ": " << min(c, j) << '\n';
	}
}
