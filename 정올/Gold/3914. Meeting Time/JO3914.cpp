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

int n, m;
vector<pair<int, int>> graphB[101];
vector<pair<int, int>> graphE[101];
bool dpB[101][10001];
bool dpE[101][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graphB[a].push_back({ b, c });
        graphE[a].push_back({ b, d });
    }

    dpB[1][0] = true;
    dpE[1][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (dpB[i][j]) {
                for (auto p : graphB[i]) {
                    if (j + p.second <= 10000) {
                        dpB[p.first][j + p.second] = true;
                    }
                }
            }

            if (dpE[i][j]) {
                for (auto p : graphE[i]) {
                    if (j + p.second <= 10000) {
                        dpE[p.first][j + p.second] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if (dpB[n][i] && dpE[n][i]) {
            cout << i;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}
