#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int h, i, a, r, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> h >> i >> a >> r >> c;
	int fi = h * i;
	int se = a * r * c;
	cout << fi - se;
}
