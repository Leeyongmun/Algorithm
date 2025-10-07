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
bool unable[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		unable[num] = true;
	}
	int ret = 987654321;
	for (int i = 1; i <= 1001; i++) {
		if (unable[i]) continue;
		for (int j = 1; j <= 1001; j++) {
			if (unable[j]) continue;
			for (int l = 1; l <= 1001; l++) {
				if (unable[l]) continue;
				int x = abs(n - i * j * l);
				if (x < ret) ret = x;
			}
		}
	}
	cout << ret;
}
