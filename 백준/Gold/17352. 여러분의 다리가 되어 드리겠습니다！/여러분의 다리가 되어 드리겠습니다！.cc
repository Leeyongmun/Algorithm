#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n;
int parent[300001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < n - 2; i++) {
		int from, to;
		cin >> from >> to;
		merge(from, to);
	}
	
	for (int i = 1; i <= n; i++) {
		find(i);
	}
	int x = parent[1];
	for (int i = 2; i <= n; i++) {
		if (x != parent[i]) {
			cout << x << ' ' << parent[i];
			break;
		}
	}
}