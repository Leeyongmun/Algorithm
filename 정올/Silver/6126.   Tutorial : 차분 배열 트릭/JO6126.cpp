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

int n, q;
int diff[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		diff[s] += c;
		diff[e + 1] -= c;
	}

	for (int i = 1; i <= 1000000; i++) {
		diff[i] += diff[i - 1];
	}

	cin >> q;

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << diff[x] << '\n';
	}
}
