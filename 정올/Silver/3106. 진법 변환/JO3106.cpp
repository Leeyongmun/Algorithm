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
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> a && a != 0) {
        cin >> s >> b;

        ll num = 0;

        for (char c : s) {
            int digit;

            if (c >= '0' && c <= '9') digit = c - '0';
            else digit = c - 'A' + 10;
            
            num = num * a + digit;
        }

        string ret = "";

        if (num == 0) ret = "0";

        while (num > 0) {
            int remain = num % b;

            if (remain < 10) {
                ret += char('0' + remain);
            }
            else {
                ret += char('A' + remain - 10);
            }

            num /= b;
        }

        reverse(ret.begin(), ret.end());

        cout << ret << '\n';
    }
}
