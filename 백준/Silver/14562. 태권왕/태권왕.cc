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

int T;
int s, g;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s >> g;
		queue<tuple<int, int, int>> q;
		q.push({0, s, g});
		while (!q.empty()) {
			int cnt = get<0>(q.front());
			int cur = get<1>(q.front());
			int goal = get<2>(q.front());
			q.pop();
			if (cur == goal) {
				cout << cnt << '\n';
				break;
			}
			if (s + 1 <= goal) {
				q.push({ cnt + 1, cur + 1, goal });
			}
			if (cur * 2 <= goal + 3) {
				q.push({ cnt + 1, cur * 2, goal + 3 });
			}
		}
	}
}