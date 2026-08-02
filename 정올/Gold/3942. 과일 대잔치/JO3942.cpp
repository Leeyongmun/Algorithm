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
using ll = long long;

int T, a, b;
bool visited[5000001];

struct State {
	int cur;
	bool isDrink;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> a >> b;

	queue<State> q;
	visited[0] = true;
	q.push({0, false});

	while (!q.empty()) {
		int cur = q.front().cur;
		bool isDrink = q.front().isDrink;
		q.pop();

		if (cur + a <= T && !visited[cur + a]) {
			visited[cur + a] = true;
			q.push({ cur + a, isDrink});
		}

		if (cur + b <= T && !visited[cur + b]) {
			visited[cur + b] = true;
			q.push({ cur + b, isDrink });
		}

		if (!visited[cur / 2] && !isDrink) {
			visited[cur / 2] = true;
			q.push({ cur / 2 , true });
		}
	}

	for (int i = T; i >= 0; i--) {
		if (visited[i]) {
			cout << i;
			break;
		}
	}
}
