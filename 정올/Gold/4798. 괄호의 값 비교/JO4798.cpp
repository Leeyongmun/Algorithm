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
using ll = long long;

int T;
string s1, s2;

vector<int> calc(string& s) {
	vector<int> v(s.size() + 2, 0);

	int depth = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			depth++;
		}
		else {
			if (i > 0 && s[i - 1] == '(') {
				v[depth - 1]++;
			}

			depth--;
		}
	}

	for (int i = 0; i < v.size() - 1; i++) {
		v[i + 1] += v[i] / 2;
		v[i] %= 2;
	}

	return v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> s1 >> s2;
		
		vector<int> a = calc(s1);
		vector<int> b = calc(s2);
		
		int size = max(a.size(), b.size());

		a.resize(size, 0);
		b.resize(size, 0);

		int ret = 0;

		for (int i = size - 1; i >= 0; i--) {
			if (a[i] > b[i]) {
				ret = 1;
				break;
			}
			else if (a[i] < b[i]) {
				ret = -1;
				break;
			}
		}

		if (ret == 1) cout << ">\n";
		else if (ret == 0) cout << "=\n";
		else cout << "<\n";
	}
}
