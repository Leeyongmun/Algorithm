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
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n;
int cnt = 0;
bool flag = false;

void print(string s) {
	cout << 1 << " ";
	
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " " << i + 2 << " ";
	}

	cout << '\n';
}

ll cal(string s) {
	ll sum = 0;
	ll cur = 1;
	char sign = '+';

	for (int i = 0; i < s.size(); i++) {
		int nxt = i + 2;

		if (s[i] == '.') {
			int tmp = nxt;
			ll p = 1;

			while (tmp > 0) {
				p *= 10;
				tmp /= 10;
			}

			cur = cur * p + nxt;
		}
		else {
			if (sign == '+') sum += cur;
			else sum -= cur;

			sign = s[i];
			cur = nxt;
		}
	}
	if (sign == '+') sum += cur;
	else sum -= cur;

	return sum;
}

void solve(int num, string s) {
	if (num == n) {
		if (cal(s) == 0) {
			cnt++;

			if (cnt <= 20) {
				print(s);
			}
		}
		return;
	}

	solve(num + 1, s + '+');
	solve(num + 1, s + '-');
	solve(num + 1, s + '.');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	solve(1, "");
	cout << cnt << '\n';
}
