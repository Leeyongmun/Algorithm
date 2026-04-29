#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 101

struct Queue {
	int data[MAX_N];
	int frontIdx;
	int rearIdx;

	void init() {
		frontIdx = 0;
		rearIdx = 0;
	}

	bool empty() {
		return frontIdx == rearIdx;
	}

	int size() {
		return (rearIdx - frontIdx + MAX_N) % MAX_N;
	}

	void push(int val) {
		data[rearIdx] = val;
		rearIdx = (rearIdx + 1) % MAX_N;
	}

	int pop() {
		int ret = data[frontIdx];
		frontIdx = (frontIdx + 1) % MAX_N;
		return ret;
	}

	int front() {
		return data[frontIdx];
	}
};

int main() {
	int T = 10;
	for (int t = 1; t <= T; t++) {
		int n, s;
		cin >> n >> s;
		vector<int> v[101];
		bool visited[101] = {};
		for (int i = 0; i < n / 2; i++) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
		}

		Queue q;
		q.init();
		q.push(s);
		visited[s] = true;
		int ret = 0;
		while (!q.empty()) {
			int mx = -1;
			int sz = q.size();
			for (int i = 0; i < sz; i++) {
				int cur = q.front();
				q.pop();
				for (int next : v[cur]) {
					if (visited[next]) continue;
					q.push(next);
					visited[next] = true;
					mx = max(mx, next);
				}
			}
			if (mx == -1) break;
			ret = mx;
		}

		cout << '#' << t << ' ' << ret << '\n';
	}
}
