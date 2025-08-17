#include<bits/stdc++.h>
using namespace std;

int n, l, r, ret = 0;
int a[54][54], visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x){
	visited[y][x] = 1;
	v.push_back({y, x});
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] == 1) continue;
		if(abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r){
			dfs(ny, nx);
		}
	}
}

int main(){
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	while(true){
		bool flag = 0;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visited[i][j] == 0){
					v.clear();
					dfs(i, j);
					if(v.size() == 1) continue;
					else{
						flag = 1;
						int sum = 0;
						for(pair<int, int> b : v){
							sum += a[b.first][b.second];
						}
						for(pair<int, int> b : v){
							a[b.first][b.second] = sum / v.size();
						}
					}
				}
			}
		}
		if(!flag) break;
		ret++;
	}
	cout << ret;
}