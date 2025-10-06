#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;

int n;
int a[51];
int ret = 6;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int cnt2 = 0;
		int num = a[i];
		int idx = i + 1;
		for (int j = 1; j < 5; j++) {
			if (idx > n - 1) {
				cnt2 += 5 - j;
				break;
			}
			if (num + j == a[idx]) {
				idx++;
			}
			else {
				cnt2++;
			}
		}
		ret = min(cnt2, ret);
	}
	cout << ((ret > 4) ? 0 : ret);
}