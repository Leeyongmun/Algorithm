#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
#include<cmath>
using namespace std;

int T;
int n, m, k;
vector<long long> v;
long long arr[1002000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	int sq = sqrt(n);
	v.resize(sq + 10);

	for (int i = 1; i <= n; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
		int idx = i / sq;
		v[idx] += num;
	}
	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long num = arr[b];
			arr[b] = c;
			int idx = b / sq;
			v[idx] += c - num;
		}
		else {
			int idx1 = b / sq;
			int idx2 = c / sq;
			long long sum = 0;
			if (idx1 == idx2) {
				for (int j = b; j <= c; j++) {
					sum += arr[j];
				}
				cout << sum << '\n';
			}
			else {
				for (int j = b; j < sq * (idx1 + 1); j++) {
					sum += arr[j];
				}
				idx1++;
				while (idx1 < idx2) {
					sum += v[idx1];
					idx1++;
				}
				for (int j = sq * idx2; j <= c; j++) {
					sum += arr[j];
				}
				cout << sum << '\n';
			}
		}
	}
}