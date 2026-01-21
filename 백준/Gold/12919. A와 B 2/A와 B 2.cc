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

string s, t;

bool check(string str) {
	if (str.size() == s.size()) {
		if (str == s) return true;
		return false;
	}
	string tmp = str;
	if (str.back() == 'A') {
		tmp.pop_back();
		if (check(tmp)) return true;
	}
	if (str.front() == 'B') {
		reverse(str.begin(), str.end());
		tmp = str;
		tmp.pop_back();
		if (check(tmp)) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t;
	if (check(t)) {
		cout << 1;
	}
	else cout << 0;
}