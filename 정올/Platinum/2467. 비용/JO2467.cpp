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

struct Edge {
	int w, x, y;

	bool operator < (const Edge& other) const {
		return w < other.w;
	}
};

const ll MOD = 1e9;

int n, m;
int parent[100001];
int sz[100001];
vector<Edge> v;

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

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back({ w, x, y });
	}

	sort(v.begin(), v.end());

	vector<ll> prefix(m);

	ll sum = 0;

	for (int i = 0; i < m; i++) {
		sum += v[i].w;
		prefix[i] = sum;
	}

	ll ret = 0;

	for (int i = m - 1; i >= 0; i--) {
		int x = find(v[i].x);
		int y = find(v[i].y);

		if (x == y) continue;

		ll cnt = (1LL * sz[x] * sz[y]) % MOD;

		ll cost = prefix[i] % MOD;

		ret = (ret + cnt * cost) % MOD;

		merge(x, y);
	}

	cout << ret;
}
