#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int n;
vector<pair<int, int>> v;
int check[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>> press;
	int l = v[0].first;
	int r = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (r < v[i].first) {
			press.push_back({ l, r });
			l = v[i].first;
			r = v[i].second;
			continue;
		}
		if (r >= v[i].first && r <= v[i].second) {
			r = v[i].second;
		}
	}
	press.push_back({ l, r });
	int ret = 0;
	check[0] = 1;

	for (int i = 0; i < press.size(); i++) {
		if (!check[i]) continue;
		int len = 2 * press[i].second - press[i].first;
		for (int j = i + 1; j < press.size(); j++) {
			if (len >= press[j].first) check[j] = 1;
			else break;
		}
		ret = press[i].second;
	}
	cout << ret;
}