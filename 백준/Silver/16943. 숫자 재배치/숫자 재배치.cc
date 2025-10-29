#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<string>

using namespace std;

string s1, s2;
string tmp;
int visited[11];
int ret = 0;

void solve(int cnt) {
	if (cnt == s1.size()) {
		if (stoi(tmp) < stoi(s2)) {
			ret = max(ret, stoi(tmp));
		}
	}

	for (int i = 0; i < s1.size(); i++) {
		if (visited[i]) continue;
		if (cnt == 0 && s1[i] == '0') continue;
		tmp.push_back(s1[i]);
		visited[i] = 1;
		solve(cnt + 1);
		tmp.pop_back();
		visited[i] = 0;
	}
}

int main() {
	cin >> s1 >> s2;
	solve(0);
	if (ret == 0) cout << -1;
	else cout << ret;
}