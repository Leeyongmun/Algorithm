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
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n;
priority_queue<int, vector<int>, greater<>> pq;
ll ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	while (pq.size() != 1) {
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		ret += x + y;
		pq.push(x + y);
	}

	cout << ret;
}
