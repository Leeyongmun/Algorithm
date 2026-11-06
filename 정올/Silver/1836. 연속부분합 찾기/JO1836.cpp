#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;

	int mx = 0;
	int sum = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(sum + a[i] < a[i]){
			sum = a[i];
			mx = max(mx, sum);
		}
		else{
			sum += a[i];
			mx = max(mx, sum);
		}
	}

	cout << mx;
}
