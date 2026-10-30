#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
struct State{
    int idx, s, e;
};

vector<State> v;

bool cmp(State a, State b){
    return a.e < b.e;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, s, e;
        cin >> x >> s >> e;
        v.push_back({x, s, e});
    }

    sort(v.begin(), v.end(), cmp);

    int t = 0;

    vector<int> ret;

    for(int i = 0; i < n; i++){
        if(t > v[i].s) continue;
        t = v[i].e;
        ret.push_back(v[i].idx);
    }

    cout << ret.size() << '\n';
    for(int x : ret){
        cout << x << ' ';
    }
}
