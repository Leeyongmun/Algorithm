#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
using namespace std;

string preorder, inorder;

void postorder(int pl, int pr, int il, int ir) {
	if (pl > pr) return;

	char root = preorder[pl];

	int idx = il;
	while (inorder[idx] != root) {
		idx++;
	}

	int leftSize = idx - il;

	postorder(pl + 1, pl + leftSize, il, idx - 1);
	postorder(pl + leftSize + 1, pr, idx + 1, ir);

	cout << root;
}

int main() {
	cin >> preorder >> inorder;
	int n = preorder.size();
	postorder(0, n - 1, 0, n - 1);
}
