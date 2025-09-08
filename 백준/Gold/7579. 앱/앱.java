import java.util.Scanner;

public class Main {
    static int n, m;
    static int[] a;
    static int[] cost;
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n + 1];
        cost = new int[n + 1];
        
        for(int i = 1; i <= n; i++){
            a[i] = sc.nextInt();
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cost[i] = sc.nextInt();
            sum += cost[i];
        }
        dp = new int[sum + 1];
        for(int i = 1; i <= n; i++){
            for(int j = sum; j >= cost[i]; j--){
                dp[j] = Math.max(dp[j], dp[j - cost[i]] + a[i]);
            }
        }
        int ret = 0;
        for(int i = 0; i <= sum; i++){
            if(dp[i] >= m){
                ret = i;
                break;
            }
        }
        System.out.println(ret);
    }
}
