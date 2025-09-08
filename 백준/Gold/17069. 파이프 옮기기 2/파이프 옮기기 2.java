import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static long[][][] dp;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a[i][j] = sc.nextInt();
            }
        }
        dp = new long[3][n + 1][n + 1];
        dp[0][1][2] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 3; j <= n; j++){
                if(a[i][j] == 1) continue;
                dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
                dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
                if(a[i - 1][j] == 1 || a[i][j - 1] == 1) continue;
                dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
            }
        }
        System.out.println(dp[0][n][n] + dp[1][n][n] + dp[2][n][n]);
    }
}
