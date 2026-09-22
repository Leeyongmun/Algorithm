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

int n;
int a[100001];
unordered_map<int, int> mp;
ll ret = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int sum = 0;
	mp[sum]++;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		ret += mp[sum];
		mp[sum]++;
	}

	cout << ret;
}
