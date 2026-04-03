#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n;
string s;

long long H[100001];
long long SH[100001];
long long KSH[100001];
long long DKSH[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = s.size() - 1; i >= 0; i--) {
		H[i] = H[i + 1];
		SH[i] = SH[i + 1];
		KSH[i] = KSH[i + 1];
		DKSH[i] = DKSH[i + 1];
		if (s[i] == 'H') {
			H[i]++;
		}
		else if (s[i] == 'S') {
			SH[i] += H[i + 1];
		}
		else if (s[i] == 'K') {
			KSH[i] += SH[i + 1];
		}
		else if (s[i] == 'D') {
			DKSH[i] += KSH[i + 1];
		}
	}
	cout << DKSH[0];
}