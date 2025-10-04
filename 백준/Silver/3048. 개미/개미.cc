#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
using namespace std;

int n, m;
vector<pair<char, int>> v;
string s1, s2;
int t;

int main() {
	cin >> n >> m;
	cin >> s1 >> s2;
	for (int i = n - 1; i >= 0; i--) {
		v.push_back({ s1[i], 0 });
	}
	for (int i = 0; i < m; i++) {
		v.push_back({ s2[i], 1 });
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n + m - 1; j++) {
			if (v[j].second == 0 && v[j + 1].second == 1) {
				swap(v[j], v[j + 1]);
				j++;
			}
		}
	}
	for (auto p : v) {
		cout << p.first;
	}
}