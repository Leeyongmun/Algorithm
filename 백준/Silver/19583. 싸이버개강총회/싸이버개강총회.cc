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
using namespace std;

string a, b, c;
unordered_set<string> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> c;
	
	string time, name;
	int ret = 0;
	while (cin >> time >> name) {
		if (time <= a) {
			st.insert(name);
		}
		if (time >= b && time <= c) {
			if (st.count(name)) {
				st.erase(name);
				ret++;
			}
		}
	}
	cout << ret;
}