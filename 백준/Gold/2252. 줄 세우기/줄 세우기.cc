#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> v;
int ind[32001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v.resize(n + 1);
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        ind[to]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next : v[cur]){
            ind[next]--;
            if(ind[next] == 0){
                q.push(next);
            }
        }
        cout << cur << " ";
    }
}