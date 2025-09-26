#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n;
stack<pair<int,int>> stk;
vector<int> v, ret;

int main() {
	cin >> n;
	v.resize(n + 1);
	ret.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	stk.push({v[1], 1});
	ret[1] = 0;
	for (int i = 2; i <= n; i++) {
		while (!stk.empty() && stk.top().first < v[i]) stk.pop();
		if (stk.empty()) ret[i] = 0;
		else ret[i] = stk.top().second;
		stk.push({ v[i], i });
	}
	for (int i = 1; i <= n; i++) {
		cout << ret[i] << ' ';
	}
}