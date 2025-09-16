#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<string>
using namespace std;

int n;
int a[500][500];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };
int ddy[4][10] = { {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
	{-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, -2, -1} };
int ddx[4][10] = { {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}, {1, -1, 1, -1, 2, -2, 1, -1, 0, 0 }, 
	{-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {1, -1, 1, -1, 2, -2, 1, -1, 0, 0} };
int per[9] = { 1, 1, 7, 7, 2, 2, 10, 10, 5 };
int dir = 0;
int ret = 0;

void tornado(int y, int x) {
	int sand = a[y][x];
	int save = sand;
	for (int i = 0; i < 9; i++) {
		int ny = y + ddy[dir][i];
		int nx = x + ddx[dir][i];
		int tmp = (sand * per[i]) / 100;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			ret += tmp;
		}
		else a[ny][nx] += tmp;
		save -= tmp;
	}
	int ny = y + ddy[dir][9];
	int nx = x + ddx[dir][9];
	if (ny < 0 || nx < 0 || ny >= n || nx >= n) ret += save;
	else a[ny][nx] += save;
	a[y][x] = 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int y = n / 2;
	int x = n / 2;
	int move = 1;
	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < move; j++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				tornado(ny, nx);
				x = nx;
				y = ny;
			}
			dir = (dir + 1) % 4;
		}
		move++;
		if (move == n) {
			for (int i = 0; i < move - 1; i++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				tornado(ny, nx);
				x = nx;
				y = ny;
			}
			break;
		}
	}
	cout << ret;
}