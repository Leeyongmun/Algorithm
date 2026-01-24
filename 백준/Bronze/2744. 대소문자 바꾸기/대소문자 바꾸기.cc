#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 'a' - 'A';
		}
		else {
			s[i] -= 'a' - 'A';
		}
	}
	cout << s;
}