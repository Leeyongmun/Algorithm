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
vector<int> a;
vector<int> ind;
vector<int> nxt;
vector<bool> visited;

void go(int cur) {
	while (!visited[cur]) {
		visited[cur] = true;
		cur = nxt[cur];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a.resize(n);
	ind.resize(n);
	nxt.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (i == 0) nxt[i] = 1;
		else if (i == n - 1) nxt[i] = n - 2;
		else {
			int left = a[i] - a[i - 1];
			int right = a[i + 1] - a[i];
			if (left <= right) nxt[i] = i - 1;
			else nxt[i] = i + 1;
		}
		ind[nxt[i]]++;
	}

	int ret = 0;

	for (int i = 0; i < n; i++) {
		if (ind[i] == 0) {
			ret++;
			go(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ret++;
			go(i);
		}
	}

	cout << ret;
}
