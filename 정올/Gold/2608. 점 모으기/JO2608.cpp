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

int n, m;
vector<int> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	x.resize(m);
	y.resize(m);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int ret = 0;
	int midX = x[m / 2];
	int midY = y[m / 2];

	for (int i = 0; i < m; i++) {
		ret += abs(x[i] - midX);
		ret += abs(y[i] - midY);
	}

	cout << ret;
}
