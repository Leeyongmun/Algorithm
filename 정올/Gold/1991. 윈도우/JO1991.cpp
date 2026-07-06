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
using namespace std;

int n, k;
int a[1000001];
priority_queue<pair<int, int>> maxPq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minPq;
vector<int> mx, mn;

int main() { 
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (maxPq.size() < k - 1) {
			maxPq.push({ a[i], i });
			minPq.push({ a[i], i });
			continue;
		}
		maxPq.push({ a[i], i });
		minPq.push({ a[i], i });
		while (maxPq.top().second < i - k + 1) {
			maxPq.pop();
		}
		while (minPq.top().second < i - k + 1) {
			minPq.pop();
		}
		mx.push_back(maxPq.top().first);
		mn.push_back(minPq.top().first);
	}

	for (int x : mn) {
		cout << x << ' ';
	}
	cout << '\n';
	for (int x : mx) {
		cout << x << ' ';
	}
}
