import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] dp;
    static int[] coin;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        dp = new int[10001];
        coin = new int[n];
        for(int i = 0; i < n; i++){
            coin[i] = sc.nextInt();
            if(coin[i] <= k){
                dp[coin[i]] = 1;
            }
        }
        Arrays.sort(coin);
        Arrays.fill(dp, 987654321);
        dp[0] = 0;
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                if(i >= coin[j]){
                    dp[i] = Math.min(dp[i], dp[i - coin[j]] + 1);
                }
                else break;
            }
        }
        System.out.println(dp[k] == 987654321 ? -1 : dp[k]);
    }
}
