#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
#include<cmath>
#include<queue>
using namespace std;

int n;
bool check[201];
vector<int> v1, v2;

int main() {
	cin >> n;
	v1.resize(2 * n + 1);
	v2.resize(2 * n + 1);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1[num] = 1;
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (!v1[i]) v2[i] = 1;
	}
	bool turn = true;
	int sang = n;
	int geun = n;
	int i = 1;

	while (sang > 0 && geun > 0) {
		if (turn) {
			if (v1[i]) {
				v1[i] = 0;
				sang--;
				turn = !turn;
			}
		}
		else {
			if (v2[i]) {
				v2[i] = 0;
				geun--;
				turn = !turn;
			}
		}
		i++;
		if (i == 2 * n + 1) {
			i = 1;
			turn = !turn;
		}
	}
	cout << geun << '\n' << sang;
}