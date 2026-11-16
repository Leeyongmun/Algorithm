#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int sy, sx, ey, ex;
int visited[101][101];
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;

    memset(visited, -1, sizeof(visited));

    queue<pair<int,int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == ey && x == ex){
            cout << visited[y][x];
            break;
        }

        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if(visited[ny][nx] != -1) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}
