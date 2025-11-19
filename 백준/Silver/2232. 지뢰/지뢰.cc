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
int a[50001];
int check[50001];
vector<pair<int, int>> landmine;
vector<int> ret;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		landmine.push_back({ a[i], i });
	}
	sort(landmine.begin(), landmine.end(), greater<pair<int,int>>());
	
	for (int i = 0; i < landmine.size(); i++) {
		if (cnt == n) break;
		if (check[landmine[i].second]) continue;
		int idx = landmine[i].second;
		check[idx] = 1;
		ret.push_back(idx);
		int tmp = idx;
		while (tmp > 1 && a[tmp] > a[tmp - 1]) {
			check[--tmp] = 1;
			cnt++;
		}
		tmp = idx;
		while (tmp < n && a[tmp] > a[tmp + 1]) {
			check[++tmp] = 1;
			cnt++;
		}
	}
	sort(ret.begin(), ret.end());
	for (int i : ret) {
		cout << i << '\n';
	}
}