#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int n, m;
vector<int> v, tmp;
bool visited[10];

void solve(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = -1;

	for (int i = idx; i < n; i++) {
		if (visited[i]) continue;
		if (v[i] == prev) continue;
		tmp.push_back(v[i]);
		visited[i] = true;
		prev = v[i];
		solve(cnt + 1, i + 1);
		visited[i] = false;
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	solve(0, 0);
}