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

int n, m;
vector<int> parent;
vector<int> sz;
vector<int> edge;

void init() {
	parent.resize(n + 1);
	sz.assign(n + 1, 1);
	edge.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x == y) {
		edge[x]++;
		return;
	}
	parent[y] = x;
	sz[x] += sz[y];
	edge[x] += edge[y] + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int t = 1; ;t++) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		init();
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			merge(from, to);
		}
		unordered_set<int> st;
		for (int i = 1; i <= n; i++) {
			int x = find(i);
			if (sz[x] == edge[x] + 1) {
				st.insert(x);
			}
		}

		cout << "Case " << t << ": ";

		if (st.size() == 0) {
			cout << "No trees." << '\n';
		}
		else if (st.size() == 1) {
			cout << "There is one tree." << '\n';
		}
		else {
			cout << "A forest of " << st.size() << " trees.\n";
		}
	}
}