#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

string s, s1, s2;
int dp[21][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) { 
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == s1[i]) {
                if (j == 0) dp[0][0]++;
                else dp[j][0] += dp[j - 1][1];
            }
            if (s[j] == s2[i]) {
                if (j == 0) dp[0][1]++;
                else dp[j][1] += dp[j - 1][0];
            }
        }
    }

    cout << dp[s.size() - 1][0] + dp[s.size() - 1][1];
}
