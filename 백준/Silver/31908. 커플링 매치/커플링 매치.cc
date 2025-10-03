#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<unordered_map>
using namespace std; 

int n;
unordered_map<string, vector<string>> mp;

int main() {
	cin >> n;
	int num = 1;
	for (int i = 0; i < n; i++) {
		string p, r;
		cin >> p >> r;
		if (r[0] == '-') continue;
		mp[r].push_back(p);
	}
	int cnt = 0;
	for (auto val : mp) {
		if (val.second.size() == 2) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (auto val : mp) {
		if (val.second.size() == 2) {
			for (string s : val.second) {
				cout << s << ' ';
			}
			cout << '\n';
		}
	}
}