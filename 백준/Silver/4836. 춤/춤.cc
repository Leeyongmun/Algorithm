#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
#include<cmath>
#include<queue>
using namespace std;

string s;
vector<string> dance;
bool have_twirl, have_hop, have_dip;

void init() {
	have_hop = false;
	have_twirl = false;
	have_dip = false;
	dance.clear();
}

void split() {
	int idx = 0;
	while (true) {
		if (s.find(' ', idx) == string::npos) {
			string  s_tmp = s.substr(idx);
			if (s_tmp == "twirl") have_twirl = true;
			else if (s_tmp == "hop") have_hop = true;
			else if (s_tmp == "dip") have_dip = true;
			dance.push_back(s_tmp);
			break;
		}
		int e = s.find(' ', idx);
		string  s_tmp = s.substr(idx, e - idx);
		if (s_tmp == "twirl") have_twirl = true;
		else if (s_tmp == "hop") have_hop = true;
		else if (s_tmp == "dip") have_dip = true;
		dance.push_back(s_tmp);
		idx = e + 1;
	}
}

int main() {
	while (getline(cin, s)) {
		init();
		split();
		
		bool check[6] = { false };
		for (int i = 0; i < dance.size(); i++) {
			if (dance[i] == "dip") {
				if (i >= 2) {
					if (dance[i - 1] != "jiggle" && dance[i - 2] != "jiggle" && (i == dance.size() - 1 || dance[i + 1] != "twirl")) {
						check[1] = true;
						dance[i] = "DIP";
					}
				}
				else if (i == 1) {
					if (dance[i - 1] != "jiggle" && dance[i + 1] != "twirl") {
						check[1] = true;
						dance[i] = "DIP";
					}
				}
				else {
					if (dance[i + 1] != "twirl") {
						check[1] = true;
						dance[i] = "DIP";
					}
				}
			}
		}
		int end = dance.size() - 1;
		if (dance[end] != "clap" || dance[end - 1] != "stomp" || dance[end - 2] != "clap") {
			check[2] = true;
		}

		if (have_twirl && !have_hop) {
			check[3] = true;
		}

		if (dance[0] == "jiggle") {
			check[4] = true;
		}

		if (!have_dip) {
			check[5] = true;
		}

		int cnt = 0;

		for (int i = 1; i <= 5; i++) {
			if (check[i]) cnt++;
		}

		if (cnt == 0) {
			cout << "form ok: ";
			for (int i = 0; i < dance.size(); i++) {
				cout << dance[i] << ' ';
			}
			cout << '\n';
		}
		else {
			if (cnt == 1) cout << "form error ";
			else cout << "form errors ";
			for (int i = 1; i <= 5; i++) {
				if (check[i]) {
					if (cnt > 2) {
						cout << i << ", ";
					}
					else if (cnt == 2) {
						cout << i << " and ";
					}
					else if (cnt == 1) {
						cout << i << ": ";
					}
					cnt--;
					if (cnt == 0) {
						break;
					}
				}
			}
			for (int i = 0; i < dance.size(); i++) {
				cout << dance[i] << ' ';
			}
			cout << '\n';
		}
	}

}