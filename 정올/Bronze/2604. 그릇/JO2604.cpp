#include<iostream>
using namespace std;

string s;

int main(){
    cin >> s;

    char pre = s[0];
    int ret = 10;

    for(int i = 1; i < s.size(); i++){
        if(pre == s[i]){
            ret += 5;
        }
        else{
            pre = s[i];
            ret += 10;
        }
    }

    cout << ret;
}
