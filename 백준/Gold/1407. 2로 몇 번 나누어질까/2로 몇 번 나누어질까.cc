#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
using namespace std;

long long a, b;

long long f(long long x) {
	long long ret = x;
	for (long long i = 2; i <= x; i *= 2) {
		ret += (x / i) * (i / 2);
	}
	return ret;
}

int main() {
	cin >> a >> b;
	cout << f(b) - f(a - 1);
}