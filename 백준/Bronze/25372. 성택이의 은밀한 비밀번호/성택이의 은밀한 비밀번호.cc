#include<iostream>
using namespace std;

int n;
string s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s.size() >= 6 && s.size() <= 9){
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}