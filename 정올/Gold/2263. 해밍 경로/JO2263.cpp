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

const int INF = 987654321;

int n, k, m;
int a[100001];
int dist[100001];
int parent[100001];
unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++) {
            if (s[j] == '1') {
                a[i] += (1 << (k - j - 1));
            }
        }
        mp[a[i]] = i;
    }

    fill(dist, dist + 100001, INF);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < k; i++) {
            int nmask = a[cur] ^ (1 << i);
            if (!mp.count(nmask)) continue;
            int next = mp[nmask];
            if (dist[next] != INF) continue;
            dist[next] = dist[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vector<int> ret;
        if (dist[x] == INF) {
            cout << -1 << '\n';
            continue;
        }
        while (x != 0) {
            ret.push_back(x);
            x = parent[x];
        }
        for (int i = ret.size() - 1; i >= 0; i--) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
    }
}
