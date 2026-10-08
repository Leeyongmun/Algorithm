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

int n, m, k;
char s[501];
int lgraph[1001];
int rgraph[1001];
int jump[30][1001];
int LOG = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        lgraph[i] = l;
        rgraph[i] = r;
    }

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 0; j < m; j++) {
            int nxt = -1;
            if (s[j] == 'L') {
                nxt = lgraph[cur];
            }
            else {
                nxt = rgraph[cur];
            }
            cur = nxt;
        }
        jump[0][i] = cur;
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }

    int cur = 1;

    for (int i = 0; i < LOG; i++) {
        if (k & (1LL << i)) {
            cur = jump[i][cur];
        }
    }

    cout << cur;
}
