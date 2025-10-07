#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int n;
vector<bool> v(10000001, true);

int main() {
	cin >> n;
	v[0] = false;
	v[1] = false;
	for (int i = 2; i * i <= 10000000; i++) {
		if (!v[i]) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			v[j] = false;
		}
	}
	for (int i = n; i <= 10000000; i++) {
		if (v[i]) {
			string s = to_string(i);
			reverse(s.begin(), s.end());
			if (stoi(s) == i) {
				cout << i;
				return 0;
			}
		}
	}
}
