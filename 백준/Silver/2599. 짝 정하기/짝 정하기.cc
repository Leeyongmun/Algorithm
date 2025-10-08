#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int n;
pair<int, int> p[3];

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> p[i].first >> p[i].second;
	}
	int ab, ac, ba, bc, ca, cb;
	if (p[0].first > p[1].second + p[2].second ||
		p[1].first > p[0].second + p[2].second ||
		p[2].first > p[0].second + p[1].second) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= p[0].first; i++) {
		ab = i;
		ac = p[0].first - i;
		bc = p[2].second - ac;
		ba = p[1].first - bc;
		ca = p[0].second - ba;
		cb = p[1].second - ab;
		if (bc < 0 || ba < 0 || ca < 0 || cb < 0) continue;
		if (ba + ca == p[0].second &&
			ab + cb == p[1].second &&
			ac + bc == p[2].second) {
			cout << 1 << '\n';
			cout << ab << ' ' << ac << '\n';
			cout << ba << ' ' << bc << '\n';
			cout << ca << ' ' << cb << '\n';
			return 0;
		}
	}
	cout << 0;
}