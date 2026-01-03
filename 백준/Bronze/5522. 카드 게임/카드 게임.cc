#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum;
}