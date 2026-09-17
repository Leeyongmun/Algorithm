#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
char a[4001][4001];
int visited[4001][4001];
int sy, sx, ey, ex;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                sy = i;
                sx = j;
            }
            else if(a[i][j] == 'G'){
                ey = i;
                ex = j;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 4001 * 4001, -1);

    queue<pair<int,int>> q; 
    visited[sy][sx] = 0;
    q.push({sy, sx});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == ey && x == ex){
            cout << visited[y][x];
            break;
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] != -1 || a[ny][nx] == '#') continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}
