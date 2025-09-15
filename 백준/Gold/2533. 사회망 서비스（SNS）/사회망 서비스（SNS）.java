import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static ArrayList<Integer>[] graph;
    static int[][] dp;
    static boolean[] visited;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        graph = new ArrayList[n + 1];
        dp = new int[n + 1][2];
        visited = new boolean[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < n - 1; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph[from].add(to);
            graph[to].add(from);
        }
        dfs(1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));

    }

    private static void dfs(int cur){
        visited[cur] = true;
        dp[cur][0] = 1;
        for(int next : graph[cur]){
            if(visited[next]) continue;
            dfs(next);
            dp[cur][1] += dp[next][0];
            dp[cur][0] += Math.min(dp[next][0], dp[next][1]); 
        }
    }
}
