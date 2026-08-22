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

struct State {
	int num, cnt, time;

	bool operator<(const State& other) const {
		if (cnt != other.cnt) return cnt < other.cnt;
		if (time != other.time) return time < other.time;
		return num < other.num;
	}
};

int n, m;
int cnt[101];
int t[101];
bool in[101];
set<State> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		if (in[x]) {
			st.erase({ x, cnt[x], t[x] });
			cnt[x]++;
			st.insert({ x, cnt[x], t[x] });
		}

		else {
			if (st.size() == n) {
				State tmp = *st.begin();
				in[tmp.num] = false;
				cnt[tmp.num] = 0;
				st.erase(st.begin());
			}

			cnt[x] = 1;
			t[x] = i;
			in[x] = true;
			st.insert({ x, cnt[x], t[x] });
		}
	}

	for (auto p : st) {
		cout << p.num << ' ';
	}
}
