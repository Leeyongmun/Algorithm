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
using namespace std;

int n;
int inorder[100001], postorder[100001], idx[100001];

void getPreorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = idx[postorder[pe]];
	int l = root - is;
	int r = ie - root;
	cout << inorder[root] << ' ';
	getPreorder(is, root - 1, ps, ps + l - 1);
	getPreorder(root + 1, ie, ps + l, pe - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}

	getPreorder(1, n, 1, n);
}