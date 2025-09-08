import java.util.Scanner;

public class Solution {
    static int T, n, l;
    static int[] score, cal;
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            l = sc.nextInt();
            score = new int[n + 1];
            cal = new int[n + 1];
            dp = new int[l + 1];
            for(int i = 1; i <= n; i++){
                score[i] = sc.nextInt();
                cal[i] = sc.nextInt();
            }
            for(int i = 1; i <= n; i++){
                for(int j = l; j >= cal[i]; j--){
                    dp[j] = Math.max(dp[j], dp[j - cal[i]] + score[i]);
                }
            }
            int ret = 0;
            for(int i = 0; i <= l; i++){
                ret = Math.max(dp[i], ret);
            }
            System.out.println("#" + t + " " + ret);
        }
    }
}
