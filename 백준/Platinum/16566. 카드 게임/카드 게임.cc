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

int n, m, k;
bool have[4000001];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	int sq = sqrt(n);
	v.resize(sq + 1);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		have[num] = true;
		v[num / sq]++;
	}
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		int idx = num / sq;
		while (true) {
			bool flag = false;
			if (v[idx] == 0) {
				idx++;
				continue;
			}
			for (int j = sq * idx; j < sq * (idx + 1); j++) {
				if (have[j] && j > num) {
					cout << j << '\n';
					have[j] = false;
					v[idx]--;
					flag = true;
					break;
				}
			}
			if (flag) break;
			idx++;
		}
	}
}