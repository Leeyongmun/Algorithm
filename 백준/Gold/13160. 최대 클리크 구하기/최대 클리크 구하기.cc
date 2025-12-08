#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int n;
vector<pair<int,int>> a;
vector<tuple<int,int,int>> v;
set<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int from, to;
		cin >> from >> to;
		a.push_back({ from, to });
		v.push_back({ from, 0, i });
		v.push_back({ to, 1, i });
	}

	sort(v.begin(), v.end());

	int mx = -1;
	int cnt = 0;
	int dist = -1;
	vector<int> ret;

	for (auto p : v) {
		int d = get<0>(p);
		int x = get<1>(p);
		int y = get<2>(p);
		if (x == 0) {
			cnt++;
			if (cnt > mx) {
				mx = cnt;
				dist = d;
			}
		}
		else {
			cnt--;
		}
	}
	cout << mx << '\n';
	for (int i = 0; i < a.size(); i++) {
		if (a[i].first <= dist && a[i].second >= dist) {
			cout << i + 1 << ' ';
		}
	}
}