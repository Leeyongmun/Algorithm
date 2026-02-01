#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, m, k;
int parent[100001];
int sz[100001];
int a, b;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
	sz[x] += sz[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int f, t;
		cin >> f >> t;
		if (i == k) {
			a = f;
			b = t;
		}
		else {
			merge(f, t);
		}
	}

	if (find(a) == find(b)) {
		cout << 0;
	}
	else {
		cout << 1LL * sz[find(a)] * sz[find(b)];
	}
}