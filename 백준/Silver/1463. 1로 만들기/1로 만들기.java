import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n;
    static int ret = 987654321;
    static int[] dp;

    //**** 재귀 */
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     n = sc.nextInt();
    //     solve(n, 0);
    //     System.out.println(ret);
    // }

    // private static void solve(int n, int cnt){
    //     if(n == 1){
    //         ret = Math.min(cnt, ret);
    //         return;
    //     }
    //     if(n % 3 == 0){
    //         solve(n / 3, cnt + 1);
    //     }
    //     if(n % 2 == 0){
    //         solve(n / 2, cnt + 1);
    //     }
    //     solve(n - 1, cnt + 1);
    // }

    //****** 반환 */
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     n = sc.nextInt();
    //     int ret = solve(n);
    //     System.out.println(ret);
    // }

    // private static int solve(int n){
    //     if(n == 1){
    //         return 0;
    //     }
    //     int min = solve(n - 1) + 1;
    //     if(n % 3 == 0){
    //         min = Math.min(min, solve(n / 3) + 1);
    //     }
    //     if(n % 2 == 0){
    //         min = Math.min(min, solve(n / 2) + 1);
    //     }

    //     return min;
    // }

    // ***메모이제이션 */
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     n = sc.nextInt();
    //     dp = new int[n + 1];
    //     Arrays.fill(dp, -1);
    //     System.out.println(solve(n));
    // }

    // private static int solve(int n){
    //     if(n == 1){
    //         return 0;
    //     }
    //     if(dp[n] != -1) return dp[n];
    //     int min = solve(n - 1) + 1;
    //     if(n % 3 == 0){
    //         min = Math.min(min, solve(n / 3) + 1);
    //     }
    //     if(n % 2 == 0){
    //         min = Math.min(min, solve(n / 2) + 1);
    //     }
    //     dp[n] = min;
    //     return min;
    // }

    //dp
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        dp = new int[n + 1];
        Arrays.fill(dp, 987654321);
        if(n == 1){
            System.out.println(0);
            return;
        }
        else if(n <= 3){
            System.out.println(1);
            return;
        }
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for(int i = 4; i <= n; i++){
            if(i % 3 == 0){
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
            }
            if(i % 2 == 0){
                dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            }
            dp[i] = Math.min(dp[i], dp[i - 1] + 1);
        }
        System.out.println(dp[n]);
    }
}
