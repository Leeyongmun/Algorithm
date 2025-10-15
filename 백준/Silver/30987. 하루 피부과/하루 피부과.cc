#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<queue>
#include<map>
#include<unordered_set>
#include<cstring>
#include<cmath>
using namespace std;

int x1, x2;
int a, b, c, d, e;

int f(int x) {
	return a * pow(x, 3) + b * pow(x, 2) + c * x - (d * pow(x, 2) + e * x);
}

int main() {
	cin >> x1 >> x2;
	cin >> a >> b >> c >> d >> e;
	a /= 3;
	b /= 2;
	d /= 2;
	cout << f(x2) - f(x1);
}