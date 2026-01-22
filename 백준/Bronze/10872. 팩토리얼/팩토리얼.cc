#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    int ret = 1;
    for(int i = n; i > 0; i--){
        ret *= i;
    }
    cout << ret;
}