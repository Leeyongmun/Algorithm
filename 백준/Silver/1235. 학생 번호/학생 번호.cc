#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int n;
string s[1001];
unordered_map<string, int> map;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int cnt = 1;
    while(true){
        bool flag = true;
        for(int i = 0; i < n; i++){
            string tmp = s[i].substr(s[i].size() - cnt);
            if(map.count(tmp)){
                flag = false;
                break;
            }
            map[tmp]++;
        }
        if(flag) break;
        cnt++;
    }
    cout << cnt;
}