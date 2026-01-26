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

long long a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	cout << (a + b) * (a - b);
}