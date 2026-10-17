#include<iostream>
using namespace std;

int a, b;

int GCD(int a, int b){
    while(b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){
    cin >> a >> b;

    int x = GCD(a, b);
    cout << x << '\n';
    cout << (a * b) / x;
}
