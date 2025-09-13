import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] a;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n][n];
        dp = new int[n][1 << n];
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(tsp(0, 1));
    }

    private static int tsp(int now, int mask){
        if(mask == (1 << n) - 1){
            if(a[now][0] != 0){
                return a[now][0];
            }
            return 987654321;
        }
        if(dp[now][mask] != 0) return dp[now][mask];
        dp[now][mask] = 987654321;
        for(int i = 0; i < n; i++){
            if(a[now][i] == 0) continue;
            if((mask & (1 << i)) != 0) continue;
            int tmp = tsp(i, mask | (1 << i));
            dp[now][mask] = Math.min(dp[now][mask], tmp + a[now][i]);
        }
        return dp[now][mask];
    }
}
