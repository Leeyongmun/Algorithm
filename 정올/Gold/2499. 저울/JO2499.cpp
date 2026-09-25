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
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] > sum + 1) break;
		sum += v[i];
	}

	cout << sum + 1;
}
