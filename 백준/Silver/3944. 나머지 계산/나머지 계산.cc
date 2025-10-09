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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int b;
		string s;
		cin >> b >> s;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum += s[i] - '0';
		}
		cout << sum % (b - 1) << '\n';
	}
}