#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
vector<int> v;
vector<int> idx;
vector<int> tree;

bool cmp(int a, int b) {
	return v[a] < v[b];
}

void update(int idx) {
	while (idx <= n) {
		tree[idx] += 1;
		idx += (idx & -idx);
	}
}

int query(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	idx.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		idx[i] = i;
	}

	sort(idx.begin(), idx.end(), cmp);

	vector<int> comp(n);
	for (int i = 0; i < n; i++) {
		comp[idx[i]] = i + 1;
	}

	tree.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int idx = comp[i];
		int fast = i - query(idx);
		update(idx);
		cout << fast + 1 << '\n';
	}
}