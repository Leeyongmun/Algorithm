#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int n;
vector<int> graph[10001];
bool check[10001];
bool flag = false;

void dfs(int cur){
    if(check[cur]){
        cout << cur;
        return;
    }
    check[cur] = true;
    for(int next : graph[cur]){
        dfs(next);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int p, s;
        cin >> p >> s;
        graph[s].push_back(p);
    }

    int x, y;
    cin >> x >> y;
    dfs(x);
    dfs(y);
}
