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
int a[100002];

int main() {
	cin >> n;
	
	int x;
	cin >> x;

	int total = x;

	int curMax = x;
	int maxSum = x;
	int curMin = x;
	int minSum = x;

	for (int i = 1; i < n; i++) {
		cin >> x;
		total += x;

		curMax = max(x, curMax + x);
		maxSum = max(maxSum, curMax);

		curMin = min(x, curMin + x);
		minSum = min(minSum, curMin);
	}

	if (maxSum < 0) cout << maxSum;
	else cout << max(maxSum, total - minSum);
}
