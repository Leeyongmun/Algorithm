#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<vector<pair<int,int>>> v(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cost;
            cin >> cost;
            if(i == j) continue;
            v[i].push_back({cost, j});
            v[j].push_back({cost, i});
        }
    }
    vector<int> minEdge(n + 1, 987654321);
    vector<bool> visited(n + 1, false);
    minEdge[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    long long ret = 0;
    int cnt = 0;
    while(!pq.empty() && cnt < n){
        pair<int,int> now = pq.top();
        pq.pop();
        int cost = now.first;
        int cur = now.second;
        if(visited[cur]) continue;
        visited[cur] = true;
        cnt++;
        ret += cost;
        for(auto next : v[cur]){
            if(!visited[next.second] && minEdge[next.second] > next.first){
                minEdge[next.second] = next.first;
                pq.push(next);
            }
        }
    }
    cout << ret;
}