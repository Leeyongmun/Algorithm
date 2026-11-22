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

int n, m;
int parent[1001];
vector<int> bad[1001];
int cnt;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
    cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    cnt = n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        char c;
        int a, b;

        cin >> c >> a >> b;

        if (c == 'E') {
            for (int x : bad[a]) {
                merge(x, b);
            }

            for (int x : bad[b]) {
                merge(x, a);
            }

            bad[a].push_back(b);
            bad[b].push_back(a);
        }

        else {
            merge(a, b);
        }
    }

    cout << cnt;
}