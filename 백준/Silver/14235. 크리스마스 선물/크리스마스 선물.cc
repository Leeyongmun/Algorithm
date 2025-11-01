#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<deque>
#include<string>
#include<cmath>
#include<set>
#include<queue>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) cout << -1 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			int x;
			for (int j = 0; j < a; j++) {
				cin >> x;
				pq.push(x);
			}
		}
	}
}
