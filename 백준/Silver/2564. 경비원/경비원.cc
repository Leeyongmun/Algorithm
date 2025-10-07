#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<tuple>
#include<unordered_map>
#include<map>
#include<string>
#include<unordered_set>
using namespace std;

int n, m;
int k;
vector<pair<int, int>> v;
pair<int, int> dong;
int d[] = { 1,4,2,3 };

int solve(int idx) {
	int dist = 0;
	pair<int, int> dest = v[idx];
	int dir = dong.first;
	int d_idx = 0;
	for (int i = 0; i < 4; i++) {
		if (d[i] == dir) d_idx = i;
	}
	if (dir == dest.first) return abs(dong.second - dest.second);
	if (dir == 1) dist += n - dong.second;
	else if (dir == 2) dist += dong.second;
	else if (dir == 3) dist += dong.second;
	else dist += m - dong.second;
	dir = d[(++d_idx) % 4];
	while (true) {
		if (dir == 1) {
			if (dir == dest.first) {
				dist += dest.second;
				break;
			}
			else dist += n;
		}
		else if (dir == 2) {
			if (dir == dest.first) {
				dist += n - dest.second;
				break;
			}
			else dist += n;
		}
		else if (dir == 3) {
			if (dir == dest.first) {
				dist += m - dest.second;
				break;
			}
			else dist += m;
		}
		else if (dir == 4) {
			if (dir == dest.first) {
				dist += dest.second;
				break;
			}
			else dist += m;
		}
		dir = d[(++d_idx) % 4];
	}
	if (dist > (2 * n + 2 * m) - dist) {
		return (2 * n + 2 * m) - dist;
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int dir, loc;
		cin >> dir >> loc;
		v.push_back({ dir, loc });
	}
	cin >> dong.first >> dong.second;
	int ret = 0;
	for (int i = 0; i < k; i++) {
		ret += solve(i);
	}
	cout << ret;
}