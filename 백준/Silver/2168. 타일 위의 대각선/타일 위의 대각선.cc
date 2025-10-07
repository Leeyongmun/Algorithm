#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int n, m;

int gcd(int a, int b) {
	a = a % b;
	if (a == 0) return b;
	return gcd(b, a);
}

int main() {
	cin >> n >> m;
	if (n < m) swap(n, m);
	if (int x = gcd(n, m)) {
		cout << n + m - x;
	}
	else {
		cout << n + m - 1;
	}
}