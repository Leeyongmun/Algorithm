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
#include <string>
using namespace std;
using ll = long long;

int n, k, s;
vector<pair<int, int>> l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> s;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < s) {
			l.push_back({ s - x, y });
		}
		else {
			r.push_back({ x - s, y });
		}
	}

	sort(l.rbegin(), l.rend());
	sort(r.rbegin(), r.rend());

	int ret = 0;

	for (int i = 0; i < r.size();) {
		int cnt = k;
		ret += r[i].first * 2;
		while (i < r.size()) {
			if (r[i].second > cnt) {
				r[i].second -= cnt;
				break;
			}
			else {
				cnt -= r[i].second;
				if (cnt == 0) {
					i++;
					break;
				}
				else i++;
			}
		}
	}

	for (int i = 0; i < l.size();) {
		int cnt = k;
		ret += l[i].first * 2;
		while (i < l.size()) {
			if (l[i].second > cnt) {
				l[i].second -= cnt;
				break;
			}
			else {
				cnt -= l[i].second;
				if (cnt == 0) {
					i++;
					break;
				}
				else i++;
			}
		}
	}

	cout << ret;
}
