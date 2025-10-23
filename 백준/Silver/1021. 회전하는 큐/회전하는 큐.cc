#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<queue>
#include<deque>
using namespace std;

int n, m;
int ret = 0;
int a[51];
deque<int> dq;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int target = a[i];
		int idx = 0;
		for (int j = 0; j <= dq.size(); j++) {
			if (dq[j] == target) {
				idx = j;
				break;
			}
		}
		int a = idx;
		int b = dq.size() - idx;
		if (a < b) {
			while (true) {
				if (dq.front() == target) break;
				dq.push_back(dq.front());
				dq.pop_front();
				ret++;
			}
		}
		else {
			while (true) {
				if (dq.front() == target) break;
				dq.push_front(dq.back());
				dq.pop_back();
				ret++;
			}
		}
		dq.pop_front();
	}
	cout << ret;

}