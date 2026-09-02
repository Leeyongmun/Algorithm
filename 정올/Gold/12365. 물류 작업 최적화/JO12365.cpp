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
int a[300001];
int l[300001], r[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	l[1] = a[1];

	for (int i = 2; i <= n; i++) {
		l[i] = max(a[i], l[i - 1] + a[i]);
	}

	r[n] = a[n];

	for (int i = n - 1; i > 0; i--) {
		r[i] = max(a[i], r[i + 1] + a[i]);
	}

	for (int i = 1; i <= n; i++) {
		cout << l[i] + r[i] - a[i] << ' ';
	}
}
