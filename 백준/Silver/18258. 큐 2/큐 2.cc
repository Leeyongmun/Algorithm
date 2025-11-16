#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else cout << 0 << '\n';
		}
		else if (cmd == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
			else cout << -1 << '\n';
		}
		else {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
			else cout << -1 << '\n';
		}
	}
}