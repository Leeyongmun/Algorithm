#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n, k;
int visited[100001];

int main() {
	cin >> n >> k;
	fill(visited, visited + 100001, 987654321);
	deque<int> dq;
	dq.push_back(n);
	visited[n] = 0;
	while (!dq.empty()) {
		int cur = dq.front();
		if (cur == k) break;
		dq.pop_front();
		if (cur * 2 <= 100000 && visited[cur * 2] > visited[cur]) {
			visited[cur * 2] = visited[cur];
			dq.push_front(cur * 2);
		}
		if (cur + 1 <= 100000 && visited[cur + 1] > visited[cur] + 1) {
			visited[cur + 1] = visited[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && visited[cur - 1] > visited[cur] + 1) {
			visited[cur - 1] = visited[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
	cout << visited[k];
}