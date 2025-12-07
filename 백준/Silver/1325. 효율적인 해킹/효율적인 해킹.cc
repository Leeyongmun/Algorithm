#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, tmp;
int mx = -987654321;
int ret[10004];
vector<int> v[10004];
int visited[10004];

int dfs(int here){
	visited[here] = 1;
	int cnt = 1;
	for(int there: v[here]){
		if(visited[there] == 1) continue;
		cnt += dfs(there);
	}
	return cnt;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		memset(visited, 0, sizeof(visited));
		ret[i] = dfs(i);
		mx = max(ret[i], mx);
	}

	for(int i = 1; i <= n; i++){
		if(mx == ret[i]) cout << i << ' ';
	}
	return 0;
}