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

int n;
int ret = 0;
priority_queue<string, vector<string>, greater<>> pq;
vector<pair<string, string>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        v.push_back({ s1, s2 });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        while (!pq.empty() && pq.top() <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i].second);
        ret = max(ret, (int)pq.size());
    }

    cout << ret;
}