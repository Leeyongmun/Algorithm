import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[] a;
    static int[] dp;
    static int[] pos, prev;
    static StringBuilder ret = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        dp = new int[n];
        pos = new int[n];
        prev = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < n; i++){
            prev[i] = -1;
        }
        dp[0] = a[0];
        int cnt = 1;
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(a[i] > dp[idx]){
                dp[++idx] = a[i];
                cnt++;
                pos[idx] = i;
                prev[i] = pos[idx - 1];
            }
            else{
                int tmp = lower_bound(idx + 1, a[i]);
                dp[tmp] = a[i];
                pos[tmp] = i;
                prev[i] = tmp > 0 ? pos[tmp - 1] : -1;
            }
        }
        ret.append(cnt).append('\n');

        int cur = pos[idx];
        Stack<Integer> stk = new Stack<>();
        while(cur != -1){
            stk.push(a[cur]);
            cur = prev[cur];
        }
        int size = stk.size();
        for(int i = 0; i < size; i++){
            ret.append(stk.pop()).append(" ");
        }
        System.out.println(ret);
    }

    private static int lower_bound(int end, int x){
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
