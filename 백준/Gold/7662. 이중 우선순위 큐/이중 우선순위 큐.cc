#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <unordered_map>
using namespace std;

int T;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		priority_queue<int> pq_max;
		priority_queue<int, vector<int>, greater<>> pq_min;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			char cmd;
			int num;
			cin >> cmd >> num;
			if (cmd == 'I') {
				pq_max.push(num);
				pq_min.push(num);
				mp[num]++;
			}
			else if (cmd == 'D') {
				if (num == -1 && pq_min.size()) {
					mp[pq_min.top()]--;
					pq_min.pop();
				}
				else if (num == 1 && pq_max.size()) {
					mp[pq_max.top()]--;
					pq_max.pop();
				}
				while (pq_min.size() && mp[pq_min.top()] == 0) {
					pq_min.pop();
				}
				while (pq_max.size() && mp[pq_max.top()] == 0) {
					pq_max.pop();
				}
			}
		}
		if (pq_max.empty() || pq_min.empty()) cout << "EMPTY\n";
		else cout << pq_max.top() << ' ' << pq_min.top() << '\n';
	}
}