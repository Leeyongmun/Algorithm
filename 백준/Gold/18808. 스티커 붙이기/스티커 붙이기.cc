#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int n, m, k;
int a[41][41];
pair<int, int> sz[101];
vector<vector<int>> sticker[101];
int ret = 0;

void rotate(int idx) {
	int r = sz[idx].first;
	int c = sz[idx].second;
	vector<vector<int>> tmp(c, vector<int>(r));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[j][r - 1 - i] = sticker[idx][i][j];
		}
	}
	sticker[idx] = tmp;
	sz[idx] = { c, r };
}

void check(int idx, int y, int x) {
	for (int i = y; i < y + sz[idx].first; i++) {
		for (int j = x; j < x + sz[idx].second; j++) {
			if (a[i][j] == 0 && sticker[idx][i - y][j - x] == 1) {
				a[i][j] = 1;
				ret++;
			}
		}
	}
}

void attach(int idx) {
	int cnt = 0;
	while (cnt < 4) {
		for (int i = 0; i <= n - sz[idx].first; i++) {
			for (int j = 0; j <= m - sz[idx].second; j++) {
				bool flag = false;
				for (int k = 0; k < sz[idx].first; k++) {
					for (int l = 0; l < sz[idx].second; l++) {
						if (a[i + k][j + l] == 1 && sticker[idx][k][l] == 1) {
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
				if (!flag) {
					check(idx, i, j);
					return;
				}
			}
		}
		rotate(idx);
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		sz[i] = { r, c };
		sticker[i].resize(r, vector<int>(c));
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				cin >> sticker[i][j][k];
			}
		}
	}
	for (int i = 0; i < k; i++) {
		attach(i);
	}

	cout << ret;
}