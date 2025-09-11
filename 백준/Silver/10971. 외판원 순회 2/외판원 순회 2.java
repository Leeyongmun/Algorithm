import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static boolean[] visited;
    static int ret = 987654321;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
            }
        }
        visited = new boolean[n];
        visited[0] = true;
        dfs(0, 0, 0);
        System.out.println(ret);
    }

    private static void dfs(int cur, int sum, int cnt){
        if(sum >= ret) return;
        if(cnt == n - 1){
            if(a[cur][0] > 0){
                ret = Math.min(ret, sum + a[cur][0]);
            }
            return;
        }
        
        visited[cur] = true;
        for(int i = 0; i < n; i++){
            if(a[cur][i] == 0) continue;
            if(visited[i]) continue;
            dfs(i, sum + a[cur][i], cnt + 1);
        }
        visited[cur] = false;
    }
}
