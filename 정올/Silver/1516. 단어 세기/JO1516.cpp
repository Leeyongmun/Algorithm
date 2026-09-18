#include<iostream>
#include<sstream>
#include<map>
using namespace std;

string s;

int main(){
    while(getline(cin, s)){
        if(s == "END") break;

        stringstream ss(s);
        map<string, int> mp;

        string word;
        while(ss >> word){
            mp[word]++;
        }

        for(auto p : mp){
            cout << p.first << " : " << p.second << '\n';
        }
    }
}
