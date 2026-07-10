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
int a[100001];
bool moved[100001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int p = 1;
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		while (p <= n && moved[a[p]]) {
			p++;
		}

		if (p <= n && a[p] == x) {
			p++;
		}
		else {
			moved[x] = true;
			ret++;
		}
	}

	cout << ret;
}
