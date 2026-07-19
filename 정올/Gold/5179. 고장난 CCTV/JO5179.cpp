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

int n;
map<int, pair<int, int>> mp;
int broken = 0;
int ret = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		int x;
		cin >> c >> x;

		if (c == 'L') {
			mp[x].first++;
		}
		else {
			mp[x].second++;
			broken++;
		}
	}

	int ret = broken;

	for (auto& it : mp) {
		int L = it.second.first;
		int G = it.second.second;

		broken -= G;
		ret = min(ret, broken);
		broken += L;
	}

	cout << ret;
}
