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

int n, m;
vector<vector<int>> v;
int parent[1001];

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

	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 'E') {
			v[a].push_back(b);
			v[b].push_back(a);
		}
		else {
			merge(a, b);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i].size() >= 2) {
			for (int j = 1; j < v[i].size(); j++) {
				merge(v[i][0], v[i][j]);
			}
		}
	}

	int ret = 0;
	
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) ret++;
	}

	cout << ret;
}
