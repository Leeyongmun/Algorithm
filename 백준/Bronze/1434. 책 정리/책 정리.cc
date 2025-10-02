#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
using namespace std; 

int n, m;
int book[1001], box[1001];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> book[i];
	}
	int idx1 = 0;
	int idx2 = 0;
	while (idx1 < n && idx2 < m) {
		if (box[idx1] >= book[idx2]) {
			box[idx1] -= book[idx2++];
		}
		else {
			idx1++;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += box[i];
	}
	cout << ret;
}