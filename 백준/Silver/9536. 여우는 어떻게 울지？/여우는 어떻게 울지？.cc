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

vector<string> split(string s) {
	int idx = 0;
	vector<string> rs;
	while (true) {
		int tmp = s.find(' ', idx);
		if (tmp == string::npos) {
			rs.push_back(s.substr(idx));
			break;
		}
		rs.push_back(s.substr(idx, tmp - idx));
		idx = tmp + 1;
	}
	return rs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	cin.ignore();
	for (int t = 1; t <= T; t++) {
		string s;
		getline(cin, s);
		vector<string> crying = split(s);
		unordered_set<string> st;
		while (true) {
			getline(cin, s);
			if (s == "what does the fox say?") break;
			vector<string> tmp = split(s);
			st.insert(tmp[2]);
		}
		for (string str : crying) {
			if (!st.count(str)) {
				cout << str << ' ';
			}
		}
		cout << '\n';
	}
}