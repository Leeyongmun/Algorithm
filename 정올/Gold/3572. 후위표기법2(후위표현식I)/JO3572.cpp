#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
using namespace std;

string s;

int priority(char c) {
	if (c == '+' || c == '-') return 1;
	return 2;
}

int main() {
	cin >> s;
	string ret = "";
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			ret += s[i];
		}
		else {
			while (!stk.empty() && priority(stk.top()) >= priority(s[i])) {
				ret += stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while (!stk.empty()) {
		ret += stk.top();
		stk.pop();
	}
	cout << ret;
}
