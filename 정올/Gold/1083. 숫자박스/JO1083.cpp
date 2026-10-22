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
#include<climits>
using namespace std;
using ll = long long;

const int INF = 1e9;

int n;
vector<int> a, b;
int dp[401][401];
int ndp[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    a.push_back(0);
    b.push_back(0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) b.push_back(x);
    }

    int idx_a = a.size() - 1;
    int idx_b = b.size() - 1;
    
    vector<vector<int>> dp(idx_a + 1, vector<int>(idx_b + 1, -INF));
    vector<vector<int>> ndp(idx_a + 1, vector<int>(idx_b + 1, -INF));
    dp[0][0] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= idx_a; i++) {
            fill(ndp[i].begin(), ndp[i].end(), -INF);
        }
        
        for (int i = 0; i <= min(k, idx_a); i++) {
            for (int j = 0; j <= min(k, idx_b); j++) {
                ndp[i][j] = max(ndp[i][j], dp[i][j]);
                
                if (i > 0) {
                    ndp[i][j] = max(ndp[i][j], dp[i - 1][j]);
                }

                if (j > 0) {
                    ndp[i][j] = max(ndp[i][j], dp[i][j - 1]);
                }

                if (i > 0 && j > 0) {
                    ndp[i][j] = max(ndp[i][j], dp[i - 1][j - 1] + a[i] * b[j]);
                }
            }
        }
        dp.swap(ndp);
    }

    cout << dp[idx_a][idx_b];
}
