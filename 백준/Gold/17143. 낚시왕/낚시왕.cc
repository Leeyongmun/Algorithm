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

struct Shark {
	int y, x, s, d, z;
	bool isdelete = false;

	Shark() {};

	Shark(int y, int x, int s, int d, int z) {
		this->y = y;
		this->x = x;
		this->s = s;
		this->d = d;
		this->z = z;
	}
};

int n, m, q;
Shark shark[10001];
vector<pair<int,int>> a[101][101];
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, 1, -1 };
int ret = 0;

void init_map() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			a[i][j].clear();
		}
	}
}

void fishing(int idx) {
	for (int i = 1; i <= n; i++) {
		if (a[i][idx].size()) {
			pair<int, int> fish = a[i][idx][0];
			ret += fish.first;
			shark[fish.second].isdelete = true;
			return;
		}
	}
}

void move() {
	init_map();
	for(int i = 0; i < q; i++){
		if (shark[i].isdelete) continue;
		int y = shark[i].y;
		int x = shark[i].x;
		int spd = shark[i].s;
		int d = shark[i].d;
		int z = shark[i].z;
		
		if (d == 1 || d == 2) {
			int period = 2 * (n - 1);
			if (period != 0) spd %= period;
			while (spd--) {
				if (d == 1 && y == 1) d = 2;
				else if (d == 2 && y == n) d = 1;
				y += dy[d];
			}
			shark[i].y = y;
			shark[i].d = d;
		}
		else {
			int period = 2 * (m - 1);
			if (period != 0) spd %= period;
			while (spd--) {
				if (d == 4 && x == 1) d = 3;
				else if (d == 3 && x == m) d = 4;
				x += dx[d];
			}
			shark[i].x = x;
			shark[i].d = d;
		}
		
		a[shark[i].y][shark[i].x].push_back({z, i});
	}
}

void eat() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j].size() > 1) {
				sort(a[i][j].rbegin(), a[i][j].rend());
				while (a[i][j].size() > 1) {
					int idx = a[i][j].size() - 1;
					auto fish = a[i][j][idx];
					shark[fish.second].isdelete = true;
					a[i][j].pop_back();
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) {
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		shark[i] = Shark(y, x, s, d, z);
		a[y][x].push_back({z, i});
	}
	int idx = 0;
	while (++idx <= m) {
		fishing(idx);
		move();
		eat();
	}
	cout << ret;
}