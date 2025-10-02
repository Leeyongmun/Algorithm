#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<string>
using namespace std; 

int n;
string s1, s2;

int main() {
	cin >> n >> s1 >> s2;
	if (n % 2) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i]) {
				cout << "Deletion failed";
				return 0;
			}
		}
	}
	else {
		if (s1 != s2) {
			cout << "Deletion failed";
			return 0;
		}
	}
	cout << "Deletion succeeded";
	return 0;
}