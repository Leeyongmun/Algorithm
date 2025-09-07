import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static int[][] dp;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][3];
        dp = new int[3][1001];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                a[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < 3; i++){
            Arrays.fill(dp[i], 987654321);
        }
        dp[0][0] = a[0][0];
        dp[1][0] = a[0][1];
        dp[2][0] = a[0][2];
        for(int i = 1; i < n; i++){
            dp[0][i] = Math.min(dp[1][i - 1], dp[2][i - 1]) + a[i][0];
            dp[1][i] = Math.min(dp[0][i - 1], dp[2][i - 1]) + a[i][1];
            dp[2][i] = Math.min(dp[0][i - 1], dp[1][i - 1]) + a[i][2];
        }
        System.out.println(Math.min(dp[0][n-1], Math.min(dp[1][n-1], dp[2][n-1])));
    }
}
