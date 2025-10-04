#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
using namespace std;

int n, k;
vector<int> v;

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> k;
	int size = n / k;
	for (int i = 0; i < k; i++) {
		sort(v.begin() + i * size, v.begin() + ((i + 1) * size));
	}
	for (int a : v) {
		cout << a << ' ';
	}
}