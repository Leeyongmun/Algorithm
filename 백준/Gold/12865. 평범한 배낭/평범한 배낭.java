import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] w, v;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        dp = new int[n + 1][k + 1];
        w = new int[n + 1];
        v = new int[n + 1];
        for(int i = 1; i <= n; i++){
            w[i] = sc.nextInt();
            v[i] = sc.nextInt();
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(j >= w[i]) dp[i][j] = Math.max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        int ret = 0;
        for(int i = 0; i <= k; i++){
            ret = Math.max(ret, dp[n][i]);
        }
        System.out.println(ret);
    }
}
