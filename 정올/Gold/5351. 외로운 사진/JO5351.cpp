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

int n;
string s;

int prv[500001];
int nxt[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	int lastG = -1;
	int lastH = -1;

	for (int i = 1; i < n; i++) {
		if (s[i] == 'G') {
			prv[i] = lastG;
			lastG = i;
		}
		else {
			prv[i] = lastH;
			lastH = i;
		}
	}

	lastG = n;
	lastH = n;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'G') {
			nxt[i] = lastG;
			lastG = i;
		}
		else {
			nxt[i] = lastH;
			lastH = i;
		}
	}

	ll ret = 0;

	for (int i = 0; i < n; i++) {
		ll left = i - prv[i];
		ll right = nxt[i] - i;

		ret += left * right;

		ret--;

		if (i - 1 >= 0 && s[i - 1] != s[i]) ret--;
		if (i + 1 < n && s[i + 1] != s[i]) ret--;
	}

	cout << ret;
}
