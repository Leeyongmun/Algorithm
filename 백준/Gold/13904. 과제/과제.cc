#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d, w });
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<>> pq;
	for (auto p : v) {
		int d = p.first;
		int w = p.second;

		pq.push(w);

		if (pq.size() > d) {
			pq.pop();
		}
	}

	int ret = 0;
	while (!pq.empty()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}