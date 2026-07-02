#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
using namespace std;

int n;
unordered_map<string, int> mp;

int main() {
	cin >> n;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		string tmp = a.substr(0, 2);
		if (tmp == b) continue;
		mp[tmp + b]++;
		if (mp.count(b + tmp)) {
			ret += mp[b + tmp];
		}
	}

	cout << ret;
}
