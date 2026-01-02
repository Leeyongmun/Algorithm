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

int g;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> g;
	v.push_back(1);
	int num = 2;
	while (true) {
		if (num * num - v.back() > g) {
			break;
		}
		v.push_back(num * num);
		num++;
	}
	int l = 0;
	int r = 1;
	while (true) {
		if (v[r] - v[l] >= g) {
			break;
		}
		r++;
	}
	bool flag = false;
	while (l < r && r < v.size()) {
		if (v[r] - v[l] == g) {
			cout << r + 1 << '\n';
			r++;
			flag = true;
		}
		else if (v[r] - v[l] > g) {
			l++;
		}
		else {
			r++;
		}
	}
	if (!flag) cout << -1;
}