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

int n;
int a[101][101];
int h[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                a[i][j] = 1;
            }
        }
    }

    int ret = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (a[i][j] == 1) h[j]++;
            else h[j] = 0;
        }

        stack<int> stk;

        for (int j = 0; j <= 100; j++) {
            int cur = (j == 100 ? 0 : h[j]);

            while (!stk.empty() && h[stk.top()] > cur) {
                int height = h[stk.top()];
                stk.pop();

                int width = stk.empty() ? j : j - stk.top() - 1;

                ret = max(ret, height * width);
            }

            if (j < 100) stk.push(j);
        }
    }

    cout << ret;
}
