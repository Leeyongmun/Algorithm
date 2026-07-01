#include<iostream>
using namespace std;

int n;
int a[1000001];

int main(){
    cin >> n;

    int ret = 0;

    for(int i = 0; i < n; i++){
        int h;
        cin >> h;

        if(a[h] > 0){
            a[h]--;
        } else{
            ret++;
        }

        a[h - 1]++;
    }

    cout << ret;
}
