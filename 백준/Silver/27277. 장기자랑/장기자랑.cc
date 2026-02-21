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

int n;
vector<int> v;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<>> pq2;
int ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() / 2; i++) {
		pq2.push(v[i]);
	}
	
	if (v.size() % 2) {
		ret += v[v.size() / 2];
		for (int i = v.size() - 1; i > v.size() / 2; i--) {
			pq1.push(v[i]);
		}
	}
	else {
		for (int i = v.size() - 1; i >= v.size() / 2; i--) {
			pq1.push(v[i]);
		}
	}
	if (ret == 0) {
		while (pq1.size() != 1) {
			int a = pq1.top();
			int b = pq2.top();
			ret += a - b;
			pq1.pop();
			pq2.pop();
		}
		ret += pq1.top();
	}
	else {
		while (!pq1.empty()) {
			int a = pq1.top();
			int b = pq2.top();
			ret += a - b;
			pq1.pop();
			pq2.pop();
		}
	}
	cout << ret;
}