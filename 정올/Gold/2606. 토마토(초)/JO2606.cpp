#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, h;
int a[101][101][101];
int visited[101][101][101];
int dy[] = {-1, 0, 1, 0, 0, 0};
int dx[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int ret = 0;

struct State{
    int z, y, x;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    queue<State> q;
    fill(&visited[0][0][0], &visited[0][0][0] + 101 * 101 * 101, -1);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> a[i][j][k];
                if(a[i][j][k] == 1){
                    q.push({i, j, k});
                    visited[i][j][k] = 0;
                }
            }
        }
    }

    while(!q.empty()){
        State cur = q.front();
        int y = cur.y;
        int x = cur.x;
        int z = cur.z;
        q.pop();

        ret = max(ret, visited[z][y][x]);

        for(int i = 0; i < 6; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];
            if(ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
            if(visited[nz][ny][nx] != -1 || a[nz][ny][nx] == -1) continue;
            visited[nz][ny][nx] = visited[z][y][x] + 1;
            q.push({nz, ny, nx});
            a[nz][ny][nx] = 1;
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(a[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ret;
}
