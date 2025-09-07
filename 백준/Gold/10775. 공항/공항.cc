#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int parent[100001];
int ret = 0;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y) swap(x, y);
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int g;
		cin >> g;
		g = find(g);
		if (g == 0) break;
		merge(g, g - 1);
		ret++;
	}
	cout << ret;
}