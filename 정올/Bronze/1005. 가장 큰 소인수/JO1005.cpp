#include<iostream>
using namespace std;

int n;

int getMaxPrimeFactor(int num){
    int mx = 0;
    for(int i = 2; i * i <= num; i++){
        while(num % i == 0){
            num /= i;
        }
    }
    if(num > 1) mx = num;
    return mx;
}

int main(){
    cin >> n;

    int max_prime = -1;
    int ret = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int prime = getMaxPrimeFactor(x);
        if(max_prime < prime) {
            max_prime = prime;
            ret = max(ret, x);
        }
    }

    cout << ret;
}
