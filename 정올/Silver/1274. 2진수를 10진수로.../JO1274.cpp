#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	int ret = 0;

	if (s[0] == '1') {
		ret -= 128;
	}

	int val = 64;

	for (int i = 1; i <= 8; i++) {
		if (s[i] == '1') ret += val;
		val /= 2;
	}

	cout << ret;
}
