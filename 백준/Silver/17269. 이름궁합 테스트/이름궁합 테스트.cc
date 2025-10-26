#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int n, m;
string s1, s2;
int cov[26] = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
	cin >> n >> m;
	cin >> s1 >> s2;
	string tmp = "";
	int mn = min(n, m);
	for (int i = 0; i < mn; i++) {
		tmp += cov[s1[i] - 'A'] + '0'; 
		tmp += cov[s2[i] - 'A'] + '0';
	}
	for (int i = mn; i < n; i++) tmp += cov[s1[i] - 'A'] + '0';
	for (int i = mn; i < m; i++) tmp += cov[s2[i] - 'A'] + '0';

	while (tmp.size() != 2) {
		string tmp2 = "";
		for (int i = 0; i < tmp.size() - 1; i++) {
			tmp2 += (tmp[i] - '0' + tmp[i + 1] - '0') % 10 + '0';
		}
		tmp = tmp2;
	}
	if (tmp[0] == '0') cout << tmp[1] << '%';
	else cout << tmp << '%';
}