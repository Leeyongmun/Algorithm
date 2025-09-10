import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static int ret = 0;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        graph = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            graph[from].add(to);
            graph[to].add(from);
        }
        dfs(1);
        System.out.println(ret);
    }

    private static void dfs(int cur){
        visited[cur] = true;
        for(int next : graph[cur]){
            if(visited[next]) continue;
            ret++;
            dfs(next);
        }
    }
}
