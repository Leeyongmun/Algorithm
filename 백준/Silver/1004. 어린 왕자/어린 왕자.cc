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


int T;
int x1, x2, y1_, y2;

bool check(int x, int y, int r) {
	int dist1 = (x - x1) * (x - x1) + (y - y1_) * (y - y1_);
	int dist2 = (x - x2) * (x - x2) + (y - y2) * (y - y2);
	return (dist1 < r * r) ^ (dist2 < r * r);
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> x1 >> y1_ >> x2 >> y2;
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			if (check(x, y, r)) cnt++;
		}
		cout << cnt << '\n';
	}
}