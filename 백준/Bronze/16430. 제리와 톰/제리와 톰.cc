#include<iostream>
using namespace std;

int a, b;

int main(){
    cin >> a >> b;
    a = b - a;
    for(int i = 2; i <= a; i++){
        if(a % i == 0 && b & i == 0){
            a /= i;
            b /= i;
        }
    }
    
    cout << a << ' ' << b;
}