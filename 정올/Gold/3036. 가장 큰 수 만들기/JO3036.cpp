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

int n, k;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	cin >> s;

	string ret;

	for (char cur : s) {
		while (!ret.empty() && k > 0 && ret.back() < cur) {
			ret.pop_back();
			k--;
		}
		ret.push_back(cur);
	}

	if (k > 0) {
		ret.resize(ret.size() - k);
	}

	cout << ret;
}
