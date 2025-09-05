import java.util.Scanner;

public class Main {
    static int T, n, m;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            dp = new int[31][31];
            for(int i = 0; i <= 30; i++){
                dp[i][0] = 1;
                dp[i][i] = 1;
                for(int j = 1; j < i; j++){
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            System.out.println(dp[m][n]);
        }
    }
}
