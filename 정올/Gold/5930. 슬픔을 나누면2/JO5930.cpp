#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

ll a, b;

bool dfs(ll cur) {
	if (cur < b) return false;
	if (cur == b) return true;
	if (cur % 2) {
		return dfs(cur / 2) || dfs((cur + 1) / 2);
	}
	else {
		return dfs(cur / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	if (dfs(a)) cout << 1;
	else cout << 0;
}
