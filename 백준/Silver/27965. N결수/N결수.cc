#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	long long num = 0;
	for (int i = 1; i <= n; i++) {
		int len = to_string(i).size();
		num = (num * (long long)pow(10, len)) % k;
		num = num + i % k;
	}
	cout << num % k;
}