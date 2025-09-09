#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int n;
int a[1000001];
int dp[1000001];

int lower__bound(int dp[], int end, int x) {
	int start = 0;
	while (start < end) {
		int mid = (start + end) / 2;
		if (dp[mid] >= x) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	int idx = 0;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > dp[idx]) {
			dp[++idx] = a[i];
			cnt++;
		}
		else {
			int tmp = lower__bound(dp, idx + 1, a[i]);
			dp[tmp] = a[i];
		}
	}
	cout << cnt;
}