import java.util.Scanner;

public class Main {
    static int n;
    static int[] a;
    static int[] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n];
        dp = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        dp[0] = a[0];
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(a[i] > dp[idx]){
                dp[++idx] = a[i];
            }else{
                int tmp = lower_bound(dp, idx + 1, a[i]);
                dp[tmp] = a[i];
            }
        }
        System.out.println(n - (idx + 1));
    }

    private static int lower_bound(int[] dp, int end, int x){
        int start = 0;
        while(start < end){
            int mid = (start + end) / 2;
            if(dp[mid] >= x){
                end = mid;
            }
            else{
                start = mid + 1; 
            }
        }
        return end;
    }
}
