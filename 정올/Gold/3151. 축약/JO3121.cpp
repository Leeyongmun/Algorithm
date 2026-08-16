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
#include <cctype>
using namespace std;
using ll = long long;

int q;
string s1, s2;
bool dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> q;

	for (int i = 1; i <= q; i++) {
		cin >> s1 >> s2;

		int n = s1.size();
		int m = s2.size();

		fill(&dp[0][0], &dp[0][0] + 1001 * 1001, false);

		dp[0][0] = true;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				char c = s1[i - 1];

				if (islower(c)) {
					if (dp[i - 1][j]) {
						dp[i][j] = true;
					}

					if (j > 0 && toupper(c) == s2[j - 1] && dp[i - 1][j - 1]) {
						dp[i][j] = true;
					}
				}

				else {
					if (j > 0 && c == s2[j - 1] && dp[i - 1][j - 1]) {
						dp[i][j] = true;
					}
				}
			}
		}

		cout << (dp[n][m] ? "YES" : "NO") << '\n';
	}
}
