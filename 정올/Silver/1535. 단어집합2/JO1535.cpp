#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

string s;
unordered_set<string> st;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (getline(cin, s)) {
		if (s == "END") break;

		stringstream ss(s);
		string word;;

		while (ss >> word) {
			if (st.count(word)) continue;
			st.insert(word);
			v.push_back(word);
		}

		for (string w : v) {
			cout << w << ' ';
		}
		cout << '\n';
	}
}
