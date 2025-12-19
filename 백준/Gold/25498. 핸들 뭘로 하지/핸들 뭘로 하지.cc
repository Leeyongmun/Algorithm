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
using namespace std;

int n;
string s;
vector<int> tree[500001];
int parent[500001], child[500001];
string ret = "";

bool better(int cur, int next) {
	while (cur != -1 && next != -1) {
		if (s[cur - 1] != s[next - 1]) return s[cur - 1] > s[next - 1];
		cur = child[cur];
		next = child[next];
	}
	return next == -1;
}

void dfs(int cur, int p) {
	parent[cur] = p;
	child[cur] = -1;
	for (int next : tree[cur]) {
		if (next == p) continue;
		dfs(next, cur);
		if (child[cur] == -1 || better(next, child[cur])) {
			child[cur] = next;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0);
	string ret;
	int cur = 1;
	while (cur != -1) {
		ret.push_back(s[cur - 1]);
		cur = child[cur];
	}
	cout << ret;
}