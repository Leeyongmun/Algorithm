#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

int n;
int a[101];
int ind[101];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ind[a[i]]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next = a[cur];

		ind[next]--;

		if (ind[next] == 0) q.push(next);
	}

	for (int i = 1; i <= n; i++) {
		if (ind[i] > 0) v.push_back(i);
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
