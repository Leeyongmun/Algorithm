#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
char a[21][21];
bool check[27];
int ret = 0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    ret = max(ret, cnt);

    check[a[y][x] - 'A'] = true;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(check[a[ny][nx] - 'A']) continue;
        dfs(ny, nx, cnt + 1);
    }

    check[a[y][x] - 'A'] = false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, 0, 1);

    cout << ret;
}
