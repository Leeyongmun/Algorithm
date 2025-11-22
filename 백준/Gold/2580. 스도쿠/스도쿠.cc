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

int a[10][10];
int check1[10][10], check2[10][10], check3[10][10];
vector<pair<int, int>> v;
bool flag = false;

void solve(int cnt) {
	if (flag) return;

	if (cnt == v.size()) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		flag = true;
		return;
	}

	int y = v[cnt].first;
	int x = v[cnt].second;
	int block = ((y - 1) / 3) * 3 + (x - 1) / 3 + 1;
	for (int j = 1; j <= 9; j++) {
		if (check1[y][j] || check2[x][j] || check3[block][j]) continue;
		a[y][x] = j;
		check1[y][j] = 1;
		check2[x][j] = 1;
		check3[block][j] = 1;
		solve(cnt + 1);
		if (flag) return;
		a[y][x] = 0;
		check1[y][j] = 0;
		check2[x][j] = 0;
		check3[block][j] = 0;
	}
}

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) v.push_back({ i, j });
			else {
				check1[i][a[i][j]] = 1;
				check2[j][a[i][j]] = 1;
				check3[((i - 1) / 3) * 3 + (j - 1) / 3 + 1][a[i][j]] = 1;
			}
		}
	}

	solve(0);
}