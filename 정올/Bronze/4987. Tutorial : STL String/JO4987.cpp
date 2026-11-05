#include<iostream>
#include<string>
using namespace std;

string s, t;

int main(){
    cin >> s >> t;

    while(s.find(t) != string::npos){
        int idx = s.find(t);
        s.erase(idx, t.size());
    }

    cout << s;
}
