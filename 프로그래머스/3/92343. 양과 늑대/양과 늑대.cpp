#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[18];
bool visited[1 << 17];
int answer;

void dfs(int mask, int sheep, int wolf, vector<int>& info) {
    if (sheep <= wolf) return;

    if (visited[mask]) return;
    visited[mask] = true;

    answer = max(answer, sheep);

    for (int i = 0; i < info.size(); i++) {
        if (!(mask & (1 << i))) continue;

        for (int next : graph[i]) {
            if (mask & (1 << next)) continue;

            int ns = sheep + (info[next] == 0);
            int nw = wolf + (info[next] == 1);

            if (ns <= nw) continue;

            dfs(mask | (1 << next), ns, nw, info);
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    answer = 0;
    
    for(int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    fill(visited, visited + (1 << 17), false);
    
    dfs(1, 1, 0, info);
    return answer;
}