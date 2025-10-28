#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int n;
unordered_map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x, w;
			cin >> x >> w;
			mp[w] = x;
		}
		else {
			int w;
			cin >> w;
			cout << mp[w] << '\n';
		}
	}
}