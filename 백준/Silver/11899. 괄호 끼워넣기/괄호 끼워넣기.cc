#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<unordered_set>
#include<stack>
using namespace std;

string s;
int cnt;
int mn;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		mn = min(cnt, mn);
	}
	cout << cnt - 2 * mn;
}