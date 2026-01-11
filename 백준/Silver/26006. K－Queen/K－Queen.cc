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
#include <tuple>
#include <climits>
using namespace std;

int n, k;
pair<int, int> king;
pair<int, int> queen[100001];
bool flag1 = false, flag2 = true;
unordered_set<int> sum, diff, y, x;
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	cin >> king.first >> king.second;
	int kingsum = king.first + king.second;
	int kingdiff = king.first - king.second;
	for (int i = 0; i < k; i++) {
		cin >> queen[i].first >> queen[i].second;
		y.insert(queen[i].first);
		x.insert(queen[i].second);
		sum.insert(queen[i].first + queen[i].second);
		diff.insert(queen[i].first - queen[i].second);
	}
	if (sum.count(kingsum) || diff.count(kingdiff) || y.count(king.first) || x.count(king.second)) flag1 = true;
	for (int i = 0; i < 8; i++) {
		int ny = king.first + dy[i];
		int nx = king.second + dx[i];
		if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
		if (!y.count(ny) && !x.count(nx) && !sum.count(ny + nx) && !diff.count(ny - nx)) {
			flag2 = false;
			break;
		}
	}
	if (flag1 && !flag2) cout << "CHECK";
	else if (flag1 && flag2) cout << "CHECKMATE";
	else if (!flag1 && flag2) cout << "STALEMATE";
	else cout << "NONE";
}