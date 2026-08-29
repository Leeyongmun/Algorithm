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
int check[7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	memset(check, -1, sizeof(check));

	check[0] = 0;

	ll sum = 0;
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;

		sum += x;
		
		int r = sum % 7;

		if (check[r] == -1) check[r] = i;
		else ret = max(ret, i - check[r]);
	}

	cout << ret;
}
