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

struct Trie {
	int nxt[10];
	bool isEnd;

	Trie() {
		memset(nxt, -1, sizeof(nxt));
		isEnd = false;
	}
};

vector<Trie> trie;
int T;
int n;

bool insert(string s) {
	int cur = 0;

	for (char c : s) {
		if (trie[cur].isEnd) {
			return false;
		}

		int idx = c - '0';

		if (trie[cur].nxt[idx] == -1) {
			trie[cur].nxt[idx] = trie.size();
			trie.push_back(Trie());
		}

		cur = trie[cur].nxt[idx];
	}

	for (int i = 0; i < 10; i++) {
		if (trie[cur].nxt[i] != -1) {
			return false;
		}
	}

	trie[cur].isEnd = true;
	return true;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		trie.clear();
		trie.push_back(Trie());
		vector<string> v;

		bool flag = true;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			if (flag) {
				if (!insert(s)) {
					flag = false;
				}
			}
		}

		cout << (flag ? "YES" : "NO") << '\n';
	}
}
