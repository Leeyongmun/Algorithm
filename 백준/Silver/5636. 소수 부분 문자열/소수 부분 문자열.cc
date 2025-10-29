#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>
#include<string>
#include<cmath>

using namespace std;

string s;
int check[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	check[1] = 1;
	for (int i = 2; i <= sqrt(100000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 100000; j += i) {
			check[j] = 1;
		}
	}
	while (true) {
		cin >> s;
		int ret = 0;
		if (s == "0") break;
		for (int i = 1; i <= 5; i++) {
			for (int j = 0; j < s.size() - i + 1; j++) {
				int num = stoi(s.substr(j, i));
				if (!check[num] && ret < num) {
					ret = num;
				}
			}
		}
		cout << ret << '\n';
	}
}