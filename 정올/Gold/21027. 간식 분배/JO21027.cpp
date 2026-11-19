#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int cnt[200001];
int xr[200001];
bool removed[200001];
vector<int> rev[200001];
vector<int> ret;

int main(){
    cin >> n;

    queue<int> q;

    for(int i = 1; i <= n; i++){
        cin >> cnt[i];
        for(int j = 0; j < cnt[i]; j++){
            int x;
            cin >> x;
            rev[x].push_back(i);
            xr[i] ^= x;
        }

        if(cnt[i] == 1) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cnt[cur] != 1) continue;
        int snack = xr[cur];
        if(removed[snack]) continue;

        removed[snack] = true;
        ret.push_back(cur);

        for(int next : rev[snack]){
            cnt[next]--;
            xr[next] ^= snack;
            if(cnt[next] == 1) q.push(next);
        }
    }

    if(ret.size() != n){
        cout << -1;
        return 0;
    }

    for(int x : ret){
        cout << x << ' ';
    }
}
