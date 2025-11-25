#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int n;
int a[100001];
pair<int, int> grow[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int g;
		cin >> g;
		grow[i] = { g, i };
	}
	sort(grow, grow + n);
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		ret += a[grow[i].second] + grow[i].first * i;
	}
	cout << ret;
}