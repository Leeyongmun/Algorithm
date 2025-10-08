#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int n, l;
vector<pair<int, pair<int, int>>> v;

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int d, r, g;
		cin >> d >> r >> g;
		v.push_back({ d, {r, g} });
	}
	int cur = 0;
	int t = 0;
	int idx = 0;
	while (true) {
		t++;
		if (v[idx].first != cur) {
			cur++;
		}
		else {
			if (idx < n) {
				if (t % (v[idx].second.first + v[idx].second.second) > v[idx].second.first - 1) {
					cur++;
					idx++;
					if (idx == n) {
						t += l - cur + 1;
						break;
					}
				}
			}
		}
		if (cur == l) {
			break;
		}
	}
	cout << t;
}