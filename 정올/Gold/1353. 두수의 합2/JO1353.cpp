#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[15001];
int ret = 0;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0;
    int r = n - 1;

    while(l < r){
        if(a[l] + a[r] > m){
            r--;
        }
        else if(a[l] + a[r] == m){
            ret++;
            r--;
            l++;
        }
        else{
            l++;
        }
    }

    cout << ret;
}
