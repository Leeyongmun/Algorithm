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

int n;
priority_queue<int> mxpq;
priority_queue<int, vector<int>, greater<>> mnpq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (i == 0) {
			mxpq.push(num);
		}

		else if (i == 1) {
			if (mxpq.top() > num) {
				mnpq.push(mxpq.top());
				mxpq.pop();
				mxpq.push(num);
			}
			else mnpq.push(num);
		}

		else {
			mxpq.push(num);
			if (mxpq.top() > mnpq.top()) {
				mnpq.push(mxpq.top());
				mxpq.pop();
				if (mnpq.size() > mxpq.size()) {
					mxpq.push(mnpq.top());
					mnpq.pop();
				}
			}
			if (mxpq.size() - mnpq.size() > 1) {
				mnpq.push(mxpq.top());
				mxpq.pop();
			}
		}
		cout << mxpq.top() << '\n';
	}
}