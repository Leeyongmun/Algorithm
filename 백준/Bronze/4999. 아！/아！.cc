#include <iostream>
using namespace std;

string s1, s2;

int main(){
    cin >> s1 >> s2;
    if(s1.size() >= s2.size()){
        cout << "go";
    }
    else cout << "no";
}