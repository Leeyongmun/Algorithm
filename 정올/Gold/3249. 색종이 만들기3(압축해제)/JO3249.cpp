#include<iostream>
#include<algorithm>
using namespace std;

int n;

int a[1025][1025];
string s;
int idx = -1;

void check(int y, int x, int sz){
    for(int i = y; i < y + sz; i++){
        for(int j = x; j < x + sz; j++){
            a[i][j] = 1;
        }
    }
}

void dfs(int y, int x, int sz){
    idx++;
    if(s[idx] == 'X'){
        dfs(y, x, sz / 2);
        dfs(y, x + sz / 2, sz / 2);
        dfs(y + sz / 2, x, sz / 2);
        dfs(y + sz / 2, x + sz/ 2, sz / 2);
    }
    else if(s[idx] == '1'){
        check(y, x, sz);
    }
}

int main(){
    cin >> n >> s;

    dfs(0, 0, n);

    cout << n << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}
