#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
vector<pair<int, int>> px, py, pz;
vector<tuple<int, int, int>> node;
int parent[100001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	parent[y] = x;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	px.resize(n);
	py.resize(n);
	pz.resize(n);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		int a, b, c;
		cin >> a >> b >> c;
		px[i] = { a, i };
		py[i] = { b, i };
		pz[i] = { c, i };
	}

	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	sort(pz.begin(), pz.end());

	for (int i = 0; i < n - 1; i++) {
		node.push_back({ abs(px[i].first - px[i + 1].first), px[i].second, px[i + 1].second });
		node.push_back({ abs(py[i].first - py[i + 1].first), py[i].second, py[i + 1].second });
		node.push_back({ abs(pz[i].first - pz[i + 1].first), pz[i].second, pz[i + 1].second });
	}
	sort(node.begin(), node.end());

	int cnt = 0;
	long long ret = 0;
	for (int i = 0; i < node.size(); i++) {
		int cost = get<0>(node[i]);
		int a = get<1>(node[i]);
		int b = get<2>(node[i]);
		if (merge(a, b)) {
			ret += cost;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << ret;
}