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
using namespace std;
using ll = long long;

int n, k;
vector<int> graph[1001];
string s[1001];
int a, b;
int parent[1001];
bool visited[1001];

void make_graph(int i, int j) {
    int cnt = 0;
    for (int idx = 0; idx < k; idx++) {
        if (s[i][idx] != s[j][idx]) cnt++;
        if (cnt > 1) return;
    }
    if (cnt == 1) {
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            make_graph(i, j);
        }
    }

    cin >> a >> b;

    fill(parent, parent + 1001, -1);

    queue<int> q;
    visited[a] = true;
    q.push(a);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == b) break;

        for (int next : graph[cur]) {
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
            parent[next] = cur;
        }
    }

    if (parent[b] == -1) {
        cout << -1;
        return 0;
    }

    int cur = b;
    vector<int> ret;
    
    while (cur != -1) {
        ret.push_back(cur);
        cur = parent[cur];
    }

    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }
}
