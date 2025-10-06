#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int cnt = 0;
		long long ret = 0;
		unordered_map<long long, int> mp;
		for (int j = 0; j < m; j++) {
			long long num;
			cin >> num;
			mp[num]++;
			if(cnt < mp[num]){
				cnt = mp[num];
				ret = num;
			}
		}
		if (cnt > m / 2) cout << ret << '\n';
		else cout << "SYJKGW\n";
	}
}