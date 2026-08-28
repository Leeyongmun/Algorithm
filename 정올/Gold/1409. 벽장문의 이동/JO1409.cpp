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

int n;
int a, b;
int k;
int arr[21];
int ret = 987654321;

void dfs(int idx, int a, int b, int cost) {
	if (idx == k) {
		ret = min(ret, cost);
		return;
	}

	if (cost >= ret) return;

	int target = arr[idx];

	if (target == a || target == b) {
		dfs(idx + 1, a, b, cost);
		return;
	}

	dfs(idx + 1, target, b, cost + abs(a - target));
	dfs(idx + 1, a, target, cost + abs(b - target));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	dfs(0, a, b, 0);

	cout << ret;
}
