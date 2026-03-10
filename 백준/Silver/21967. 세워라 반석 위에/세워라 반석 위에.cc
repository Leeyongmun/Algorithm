#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int n;
int a[1000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> cnt(11, 0);
	int l = 0;
	int ret = 0;

	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
		while (true) {
			int mn = 11;
			int mx = 0;
			for (int j = 1; j <= 10; j++) {
				if (cnt[j] > 0) {
					mx = max(mx, j);
					mn = min(mn, j);
				}
			}
			if (mx - mn <= 2) break;

			cnt[a[l]]--;
			l++;
		}
		ret = max(ret, i - l + 1);
	}
	cout << ret;
}
          