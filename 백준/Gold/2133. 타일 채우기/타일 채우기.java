import java.util.Scanner;

public class Main {
    static int n;
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        dp = new int[31];
        dp[0] = 1;
        dp[1] = 0;
        dp[2] = 3;
        for(int i = 4; i <= n; i++){
            if(i % 2 == 1) {
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i - 2] * dp[2];
                for(int j = i - 4; j >= 0; j -= 2){
                    dp[i] += dp[j] * 2;
                }
            }
        }
        System.out.println(dp[n]);
    }
}
