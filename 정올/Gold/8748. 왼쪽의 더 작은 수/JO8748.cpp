#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;
stack<pair<int,int>> stk;
vector<int> ret;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        while(!stk.empty() && stk.top().second > x){
            stk.pop();
        }

        if(stk.empty()){
            ret.push_back(0);
        }
        else{
            ret.push_back(stk.top().first);
        }

        stk.push({i, x});
    }

    for(int x : ret){
        cout << x << ' ';
    }
}
