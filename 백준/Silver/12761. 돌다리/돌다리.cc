#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <map>
using namespace std;

int a, b, n, m;
int visited[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> n >> m;
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		if (cur == m) break;
		q.pop();
		if (cur + 1 <= 100000 && !visited[cur + 1]) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
		if (cur + a <= 100000 && !visited[cur + a]) {
			q.push(cur + a);
			visited[cur + a] = visited[cur] + 1;
		}
		if (cur - a >= 0 && !visited[cur - a]) {
			q.push(cur - a);
			visited[cur - a] = visited[cur] + 1;
		}
		if (cur + b <= 100000 && !visited[cur + b]) {
			q.push(cur + b);
			visited[cur + b] = visited[cur] + 1;
		}
		if (cur - b >= 0 && !visited[cur - b]) {
			q.push(cur - b);
			visited[cur - b] = visited[cur] + 1;
		}
		if (cur * a <= 100000 && !visited[cur * a]) {
			q.push(cur * a);
			visited[cur * a] = visited[cur] + 1;
		}
		if (cur * b <= 100000 && !visited[cur * b]) {
			q.push(cur * b);
			visited[cur * b] = visited[cur] + 1;
		}
	}
	cout << visited[m] - 1;
}