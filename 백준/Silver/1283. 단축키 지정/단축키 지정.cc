#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;

int n;
int visited[26];
string s[31];

vector<string> split_string(string s) {
	int cur = 0;
	vector<string> sp;
	while (true) {
		int position = s.find(' ', cur);
		if (position == string::npos) {
			sp.push_back(s.substr(cur));
			break;
		}
		int len = position - cur;
		string tmp = s.substr(cur, len);
		sp.push_back(tmp);
		cur = position + 1;
	}
	return sp;
}

int main() {
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
		vector<string> split = split_string(s[i]);
		bool flag = false;

		for (int j = 0; j < split.size(); j++) {
			char ch = split[j][0];
			if (ch >= 'a' && ch <= 'z') {
				if (!visited[ch - 'a']) {
					visited[ch - 'a'] = 1;
					flag = true;
					split[j].replace(0, 1, "[" + string(1, split[j][0]) + "]");
				}
			}
			else if (ch >= 'A' && ch <= 'Z') {
				if (!visited[ch - 'A']) {
					visited[ch - 'A'] = 1;
					flag = true;
					split[j].replace(0, 1, "[" + string(1, split[j][0]) + "]");
				}
			}
			if (flag) break;
		}
		if (flag) {
			s[i] = "";
			for (int j = 0; j < split.size(); j++) {
				s[i] += split[j];
				if (j != split.size() - 1) s[i] += " ";
			}
			continue;
		}
		for (int j = 0; j < s[i].size(); j++) {
			char ch = s[i][j];
			if (ch == ' ') continue;
			if (ch >= 'a' && ch <= 'z') {
				if (!visited[ch - 'a']) {
					visited[ch - 'a'] = 1;
					s[i].replace(j, 1, "[" + string(1, ch) + "]");
					break;
				}
			}
			else if (ch >= 'A' && ch <= 'Z') {
				if (!visited[ch - 'A']) {
					visited[ch - 'A'] = 1;
					s[i].replace(j, 1, "[" + string(1, ch) + "]");
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] << '\n';
	}
}