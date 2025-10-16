#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<map>
#include<unordered_set>
#include<cstring>
#include<cmath>
using namespace std;

int t, n, m;
int a[1001];
int b[1001];
long long psum_a[1001];
long long psum_b[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) psum_a[0] = a[0];
		else psum_a[i] = psum_a[i - 1] + a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (i == 0) psum_b[0] = b[0];
		else psum_b[i] = psum_b[i - 1] + b[i];
	}
	vector<long long> aa, bb;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			aa.push_back(psum_a[j] - (i > 0 ? psum_a[i - 1] : 0));
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			bb.push_back(psum_b[j] - (i > 0 ? psum_b[i - 1] : 0));
		}
	}
	sort(bb.begin(), bb.end());
	long long cnt = 0;
	for (int i = 0; i < aa.size(); i++) {
		long long num = t - aa[i]; 
		auto low = lower_bound(bb.begin(), bb.end(), num);
		auto high = upper_bound(bb.begin(), bb.end(), num);
		cnt += high - low;
	}
	cout << cnt;
}