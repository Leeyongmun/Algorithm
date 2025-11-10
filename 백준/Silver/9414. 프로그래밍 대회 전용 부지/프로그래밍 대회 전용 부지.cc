#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<deque>
#include<queue>
#include<string>

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		int money = 5000000;
		vector<int> a;
		while (true) {
			int num;
			cin >> num;
			if (num == 0) break;
			a.push_back(num);
		}
		sort(a.rbegin(), a.rend());
		int sum = 0;
		for (int i = 0; i < a.size(); i++) {
			sum += (2 * pow(a[i], (i + 1)));
			if (sum > money) break;
		}
		if (sum > money) cout << "Too expensive\n";
		else cout << sum << '\n';
	}
}