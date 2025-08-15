import java.util.Scanner;

public class Solution {
    static int T, n, m;
    static int ret = 987654321;
    static int[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            ret = 987654321;
            n = sc.nextInt();
            m = sc.nextInt();
            a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            solve(0, 0);
            System.out.println("#" + t + " " + (ret - m));
        }
    }

    private static void solve(int cnt, int sum){
        if(cnt == n){
            if(sum >= m){
                ret = Math.min(ret, sum);
            }
            return;
        }
        solve(cnt + 1, sum + a[cnt]);
        solve(cnt + 1, sum);
    }
}
