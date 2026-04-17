#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, x;
int a[100001];

bool check(int mid) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= mid; i++) {
		pq.push({ 0, i });
	}
	for (int i = 0; i < n; i++) {
		auto p = pq.top();
		pq.pop();
		p.first += a[i];
		if (p.first > x) return false;
		pq.push(p);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int r = n;
	int l = 1;

	int ret = -1;

	while (r >= l) {
		int mid = (r + l) / 2;
		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ret;
}