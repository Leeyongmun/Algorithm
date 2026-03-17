#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int T;
int n, p, q;
int graph[101][101];
vector<int> people;

void init() {
    people.clear();
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = 987654321;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> p >> q;
        init();
        for (int i = 0; i < n; i++) {
            int person;
            cin >> person;
            people.push_back(person);
        }
        for (int i = 0; i < q; i++) {
            int from, to, dist;
            cin >> from >> to >> dist;
            if (graph[from][to] > dist) {
                graph[from][to] = dist;
                graph[to][from] = dist;
            }
        }

        for (int k = 1; k <= 100; k++) {
            for (int i = 1; i <= 100; i++) {
                for (int j = 1; j <= 100; j++) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        int idx = -1;
        long long ret = 1e18;

        for (int i = 1; i <= p; i++) {
            long long sum = 0;
            for (int j : people) {
                if (graph[j][i] == 987654321) {
                    sum = 1e18;
                    break;
                }
                sum += (long long)graph[j][i] * graph[j][i];
            }
            if (ret > sum) {
                ret = sum;
                idx = i;
            }
        }
        cout << idx << " " << ret << '\n';
    }
}