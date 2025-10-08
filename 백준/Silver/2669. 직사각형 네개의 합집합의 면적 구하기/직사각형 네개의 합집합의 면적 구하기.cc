#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int a[101][101];

int main() {
	for (int t = 0; t < 4; t++) {
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		for (int i = y; i < y2; i++) {
			for (int j = x; j < x2; j++) {
				a[i][j]++;
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (a[i][j]) ret++;
		}
	}
	cout << ret;
}