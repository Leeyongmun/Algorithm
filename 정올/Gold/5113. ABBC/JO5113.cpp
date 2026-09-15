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

string s;
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;

	vector<bool> used(s.size(), false);
	queue<int> q;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B') q.push(i);
		else if (s[i] == 'C' && !q.empty()) {
			used[q.front()] = true;
			q.pop();
			ret++;
		}
	}

	int b = 0;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'B' && !used[i]) b++;
		else if (s[i] == 'A' && b > 0) {
			b--;
			ret++;
		}
	}

	cout << ret;
}
