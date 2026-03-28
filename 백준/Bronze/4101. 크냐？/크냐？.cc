#include <iostream>
using namespace std;

int T;
int a, b;

int main(){
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        if(a > b) cout << "Yes\n";
        else cout << "No\n";
    }
}