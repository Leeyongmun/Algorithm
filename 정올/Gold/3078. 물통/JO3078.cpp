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

int a, b;
int ta, tb;
unordered_map<ll, int> mp;

ll getKey(int x, int y) {
    return 1LL * x * 100001 + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> ta >> tb;

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    mp[getKey(0, 0)] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == ta && y == tb) break;

        ll cur = getKey(x, y);

        ll next = getKey(a, y);
        if (!mp.count(next)) {
            q.push({ a, y });
            mp[next] = mp[cur] + 1;
        }

        next = getKey(x, b);
        if (!mp.count(next)) {
            q.push({ x, b });
            mp[next] = mp[cur] + 1;
        }

        next = getKey(0, y);
        if (!mp.count(next)) {
            q.push({ 0, y });
            mp[next] = mp[cur] + 1;
        }

        next = getKey(x, 0);
        if (!mp.count(next)) {
            q.push({ x, 0 });
            mp[next] = mp[cur] + 1;
        }

        int move = min(x, b - y);
        int nx = x - move;
        int ny = y + move;

        next = getKey(nx, ny);
        if (!mp.count(next)) {
            q.push({ nx, ny });
            mp[next] = mp[cur] + 1;
        }

        move = min(a - x, y);
        nx = x + move;
        ny = y - move;

        next = getKey(nx, ny);
        if (!mp.count(next)) {
            q.push({ nx, ny });
            mp[next] = mp[cur] + 1;
        }
    }

    ll key = getKey(ta, tb);

    if (mp.count(key)) {
        cout << mp[key];
    }
    else cout << -1;
}
