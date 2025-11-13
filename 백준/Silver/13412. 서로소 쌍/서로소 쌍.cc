#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

int T;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int num;
		cin >> num;
		int ret = 0;
		for (int i = 1; i <= sqrt(num); i++) {
			if (num % i == 0 && gcd(i, num / i) == 1) ret++;
		}
		cout << ret << '\n';
	}
}