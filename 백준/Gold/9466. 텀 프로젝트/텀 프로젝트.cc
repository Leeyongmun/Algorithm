#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
using namespace std;

int T, n;
bool visited[100001], done[100001];
int a[100001];
int cnt = 0;

void dfs(int cur) {
	visited[cur] = true;
	int next = a[cur];

	if (!visited[next]) {
		dfs(next);
	}

	else if (!done[next]) {
		for (int i = next; i != cur; i = a[i]) cnt++;
		cnt++;
	}

	done[cur] = true;
}

void init() {
	cnt = 0;
	fill(visited, visited + n + 1, false);
	fill(done, done + n + 1, false);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		init();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) dfs(i);
		}
		cout << n - cnt << '\n';
	}
}