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

int n;
int a[500001];
int ret[500001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<pair<int,int>> stk;

	for (int i = n - 1; i >= 0; i--) {
		if (stk.empty()) {
			stk.push({a[i], i});
			continue;
		}
		if (stk.top().first <= a[i]) {
			while (!stk.empty() && stk.top().first <= a[i]) {
				ret[stk.top().second] = i + 1;
				stk.pop();
			}
		}
		stk.push({a[i], i});
	}

	while (!stk.empty()) {
		ret[stk.top().second] = 0;
		stk.pop();
	}

	for(int i = 0; i < n; i++){
        cout << ret[i] << ' ';
    }
}
