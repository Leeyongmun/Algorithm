import java.util.ArrayDeque;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int n;
    static int[] a, dp, pos, prev;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n];
        dp = new int[n];
        pos = new int[n];
        prev = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        for(int i = 0; i < n; i++){
            prev[i] = -1;
        }
        dp[0] = a[0];
        pos[0] = 0;
        int idx = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(a[i] > dp[idx]){
                dp[++idx] = a[i];
                pos[idx] = i;
                prev[i] =pos[idx - 1];
                cnt++;
            }
            else{
                int tmp = lower_bound(dp, idx + 1, a[i]);
                dp[tmp] = a[i];
                pos[tmp] = i;
                prev[i] = tmp > 0 ? pos[tmp - 1] : -1;
            }
        }
        int cur = pos[idx];
        Stack<Integer> stk = new Stack<>();
        while(cur != -1){
            stk.push(a[cur]);
            cur = prev[cur];
        }
        System.out.println(cnt);
        int sz = stk.size();
        for(int i = 0; i < sz; i++){
            System.out.print(stk.pop() + " ");
        }
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
