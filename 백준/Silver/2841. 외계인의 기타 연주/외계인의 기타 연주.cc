#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
unordered_map<int, vector<int>> mp;
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (mp[a].empty()) {
			mp[a].push_back(b);
			ret++;
			continue;
		}
		if (mp[a].back() < b) {
			mp[a].push_back(b);
			ret++;
		}
		else if(mp[a].back() > b) {
			while (!mp[a].empty() && mp[a].back() > b) {
				mp[a].pop_back();
				ret++;
			}
			if (!mp[a].empty() && mp[a].back() == b) continue;
			mp[a].push_back(b);
			ret++;
		}
	}
	cout << ret;
}