#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<cstring>
using namespace std;

int n, m, k;
int a[11][11], b[11][11];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<deque<int>>> trees;

void spring_summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trees[i][j].empty()) continue;
			deque<int>& dq = trees[i][j];
			deque<int> alive;
			int dead = 0;

			while (!dq.empty()) {
				int age = dq.front();
				dq.pop_front();
				if (a[i][j] >= age) {
					a[i][j] -= age;
					alive.push_back(age + 1);
				}
				else {
					dead += age / 2;
					while (!dq.empty()) {
						dead += dq.front() / 2;
						dq.pop_front();
					}
					break;
				}
			}

			dq.swap(alive);
			a[i][j] += dead;
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (trees[i][j].empty()) continue;
			for (int age : trees[i][j]) {
				if (age % 5) continue;
				for (int d = 0; d < 8; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
					trees[ny][nx].push_front(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] += b[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	trees.assign(n, vector<deque<int>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}

	fill(&a[0][0], &a[0][0] + 11 * 11, 5);

	for (int i = 0; i < m; i++) {
		int y, x, z;
		cin >> y >> x >> z;
		trees[y-1][x-1].push_back(z);
	}

	while (k--) {
		spring_summer();
		fall();
		winter();
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += trees[i][j].size();
		}
	}
	cout << ret;
}