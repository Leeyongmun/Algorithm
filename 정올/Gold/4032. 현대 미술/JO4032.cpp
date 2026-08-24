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

int n;
vector<vector<int>> a;
int mnx[10], mxx[10], mny[10], mxy[10];
bool check[10];
int isPossible[10];

void checkSquare(int ey, int sy, int ex, int sx, int t) {
	if(isPossible[t] == 0) isPossible[t] = 1;
	check[t] = true;

	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (t != a[i][j]) {
				isPossible[a[i][j]] = 2;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	a.resize(n + 1, vector<int>(n + 1));

	fill(mnx, mnx + 10, 100);
	fill(mny, mny + 10, 100);

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			int x = s[j - 1] - '0';
			a[i][j] = x;
			mnx[x] = min(mnx[x], j);
			mny[x] = min(mny[x], i);
			mxx[x] = max(mxx[x], j);
			mxy[x] = max(mxy[x], i);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = a[i][j];
			if (t != 0 && !check[t]) {
				checkSquare(mxy[t], mny[t], mxx[t], mnx[t], t);
			}
		}
	}

	int ret = 0;

	for (int i = 1; i <= 9; i++) {
		if (isPossible[i] == 1) {
			ret++;
		}
	}

	cout << ret;
}
