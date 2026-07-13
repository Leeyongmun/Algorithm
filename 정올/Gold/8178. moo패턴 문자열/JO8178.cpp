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

int n, f;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> f;
	cin >> s;

	map<string, int> cnt;

	for (int i = 0; i < n - 2; i++) {
		string tmp = s.substr(i, 3);
		if (tmp[0] != tmp[1] && tmp[1] == tmp[2]) {
			cnt[tmp]++;
		}
	}

	set<string> ret;

	for (auto& p : cnt) {
		if (p.second >= f) {
			ret.insert(p.first);
		}
	}

	for (int i = 0; i < n; i++) {
		vector<string> removed;

		for (int j = max(0, i - 2); j <= min(n - 3, i); j++) {
			string tmp = s.substr(j, 3);
			if (tmp[0] != tmp[1] && tmp[1] == tmp[2]) {
				cnt[tmp]--;
				removed.push_back(tmp);
			}
		}

		char old = s[i];

		for (char c = 'a'; c <= 'z'; c++) {
			if (c == old) continue;

			s[i] = c;

			vector<string> added;

			for (int j = max(0, i - 2); j <= min(n - 3, i); j++) {
				string tmp = s.substr(j, 3);
				if (tmp[0] != tmp[1] && tmp[1] == tmp[2]) {
					cnt[tmp]++;
					added.push_back(tmp);

					if (cnt[tmp] >= f) {
						ret.insert(tmp);
					}
				}
			}

			for (auto& x : added) {
				cnt[x]--;
			}
		}
		s[i] = old;

		for (auto& x : removed) {
			cnt[x]++;
		}
	}

	cout << ret.size() << '\n';

	for (auto& x : ret) {
		cout << x << '\n';
	}
}
