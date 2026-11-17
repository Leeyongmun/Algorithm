#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

vector<int> graph[501];
int dist[501][501];
int n;

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start][start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : graph[cur]){
            if(dist[start][next] != -1) continue;
            q.push(next);
            dist[start][next] = dist[start][cur] + 1;
        }
    }
}

int main(){
    int e;

    cin >> e;

    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        n = max(n, max(a, b));
    }

    memset(dist, -1, sizeof(dist));

    for(int i = 1; i <= n; i++){
        bfs(i);
    }

    double sum = 0;
    double cnt = n * (n - 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            sum += dist[i][j];
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << (sum / cnt);
}
