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

int n;
int cnt[200001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	int s = 0;

	for (int i = 0; i <= n; i++) {
		int x = 0;
		if (cnt[i]) {
			x += cnt[i];
			cout << max(s,x) << '\n';
		}
		else {
			cout << s << '\n';
			s++;
		}
	}
}
