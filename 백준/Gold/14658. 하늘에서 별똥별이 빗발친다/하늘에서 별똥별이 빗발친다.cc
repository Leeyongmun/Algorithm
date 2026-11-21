#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<stack>
#include<cctype>
#include<string>
#include<sstream>
#include<climits>
#include<cstring>
using namespace std;
using ll = long long;

int n, m, l, K;
vector<pair<int, int>> star;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> l >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        star.push_back({ x, y });
    }

    int mx = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int x = star[i].first;
            int y = star[j].second;

            int cnt = 0;

            for (int k = 0; k < K; k++) {
                int nx = star[k].first;
                int ny = star[k].second;

                if (x <= nx && nx <= x + l && y <= ny && ny <= y + l) cnt++;
            }
            mx = max(mx, cnt);
        }
    }

    cout << K - mx;
}