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
        solve(0, 0, 0);
        System.out.println(ret);
    }
    
    private static void solve(int now, int cnt, int sum){
        if(sum >= ret) return;
        if(cnt == n - 1){
            if(a[now][0] > 0){
                ret = Math.min(ret, sum + a[now][0]);
            }
            return;
        }
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            if(a[now][i] == 0) continue;
            visited[i] = true;
            solve(i ,cnt + 1, sum + a[now][i]);
            visited[i] = false;
        }
    }
}
