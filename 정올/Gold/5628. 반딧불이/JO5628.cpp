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

int n, h;
int diff[500002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> h;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i % 2) {
			diff[1]++;
			diff[x + 1]--;
		}
		else {
			diff[h - x + 1]++;
			diff[h + 1]--;
		}
	}

	int mn = 987654321;

	for (int i = 1; i <= h; i++) {
		diff[i] += diff[i - 1];
		mn = min(mn, diff[i]);
	}

	int cnt = 0;
	
	for (int i = 1; i <= h; i++) {
		if (mn == diff[i]) cnt++;
	}

	cout << mn << ' ' << cnt;
}
