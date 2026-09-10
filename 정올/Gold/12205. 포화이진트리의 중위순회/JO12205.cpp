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

int h, n;

void solve(int num, int height, int cnt) {
	int mid = 1 << (h - height);

	if (cnt == mid) {
		cout << num;
		return;
	}

	if (cnt < mid) {
		solve(num * 2, height + 1, cnt);
	}
	else {
		solve(num * 2 + 1, height + 1, cnt - mid);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> n;
	solve(1, 0, n);
}
