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

int n, w;
vector<pair<int, int>> v;
int dp[1001][1001];

int get_distance1(int s, int e) {
    if (s == 0) {
        return abs(1 - v[e].first) + abs(1 - v[e].second);
    }
    return abs(v[s].first - v[e].first) + abs(v[s].second - v[e].second);
}

int get_distance2(int s, int e) {
    if (s == 0) {
        return abs(n - v[e].first) + abs(n - v[e].second);
    }
    return abs(v[s].first - v[e].first) + abs(v[s].second - v[e].second);
}

int dfs(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    int next = max(i, j) + 1;
    if (next > w) return 0;

    int a = get_distance1(i, next) + dfs(next, j);
    int b = get_distance2(j, next) + dfs(i, next);

    return dp[i][j] = min(a, b);
}

void trace(int i, int j) {
    int next = max(i, j) + 1;
    if (next > w) return;

    int a = get_distance1(i, next) + dfs(next, j);
    int b = get_distance2(j, next) + dfs(i, next);

    if (a <= b) {
        cout << 1 << '\n';
        trace(next, j);
    }
    else {
        cout << 2 << '\n';
        trace(i, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;

    v.resize(w + 1);
    for (int i = 1; i <= w; i++) {
        cin >> v[i].first >> v[i].second;
    }

    fill(&dp[0][0], &dp[0][0] + 1001 * 1001, -1);

    cout << dfs(0, 0) << '\n';
    trace(0, 0);
}
