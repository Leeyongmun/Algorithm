import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[] a;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        dp = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        dp[0] = a[0];
        int idx = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(a[i] > dp[idx]){
                dp[++idx] = a[i];
                cnt++;
            }
            else{
                int tmp = lower_bound(idx + 1, a[i]);
                dp[tmp] = a[i];
            }
        }
        System.out.println(cnt);
    }

    static private int lower_bound(int end, int x){
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
