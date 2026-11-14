#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[100001];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    long long sum = a[1];
    int ret = 0;

    for(int i = 2; i <= n; i++){
        if(sum < a[i]){
            while(sum < a[i]){
                sum *= 2;
                ret++;
            }
        }
        sum += a[i];
    }

    cout << ret;
}
