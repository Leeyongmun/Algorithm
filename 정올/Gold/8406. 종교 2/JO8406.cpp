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

int n, q;
int parent[50001];
int cnt[50001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
	cnt[x] += cnt[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < q; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		else {
			int x;
			cin >> x;
			cout << cnt[find(x)] << '\n';
		}
	}
}
