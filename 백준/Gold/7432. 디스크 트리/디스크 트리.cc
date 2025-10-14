#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<map>
#include<unordered_set>
using namespace std;

struct Trie {
	map<string, Trie*> child;
};

int n;

void insert(Trie* root, vector<string> s) {
	Trie* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->child[s[i]] == nullptr) {
			cur->child[s[i]] = new Trie();
		}
		cur = cur->child[s[i]];
	}
}

void printblank(int cnt) {
	for (int i = 0; i < cnt; i++) {
		cout << ' ';
	}
}

void printTrie(Trie* root, int cnt) {
	Trie* cur = root;
	for (auto mp : cur->child) {
		printblank(cnt);
		cout << mp.first << '\n';
		printTrie(mp.second, cnt + 1);
	}
}

vector<string> split(string s) {
	int start = 0;
	vector<string> sp;
	while (true) {
		int idx = s.find('\\',  start);
		if (idx == string::npos) {
			sp.push_back(s.substr(start));
			break;
		}
		sp.push_back(s.substr(start, idx - start));
		start = idx + 1;
	}
	return sp;
}

int main() {
	cin >> n;
	Trie* root = new Trie();
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		insert(root, split(input));
	}
	printTrie(root, 0);
}