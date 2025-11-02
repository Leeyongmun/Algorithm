#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n, k;
priority_queue<int> pq[12];
int player[12];
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p, w;
		cin >> p >> w;
		pq[p].push(w);
	}
	while (k--) {
		for (int i = 1; i <= 11; i++) {
			if (pq[i].empty()) continue;
			if (player[i] < pq[i].top()) {
				player[i] = pq[i].top();
				pq[i].pop();
			}
		}
		for (int i = 1; i <= 11; i++) {
			if (pq[i].empty()) {
				if (player[i] > 0) player[i]--;
				continue;
			}
			if (player[i] - 1 < pq[i].top()) {
				player[i] = pq[i].top();
				pq[i].pop();
				if (player[i] - 1 > 0) pq[i].push(player[i] - 1);
			}
			else {
				if (player[i] > 0) player[i]--;
			}
		}
	}
	for (int i = 1; i <= 11; i++) {
		if (player[i] > 0) ret += player[i];
	}
	cout << ret;
}