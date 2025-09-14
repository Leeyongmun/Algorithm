import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[] b, c;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        b = new int[n + 1];
        c = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= n; i++){
            b[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int costSum = 0;
        for(int i = 1; i <= n; i++){
            c[i] = Integer.parseInt(st.nextToken());
            costSum += c[i];
        }
        dp = new int[n + 1][costSum + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= costSum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= c[i]){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - c[i]] + b[i]);
                }
            }
        }
        for(int i = 0; i <= costSum; i++){
            if(dp[n][i] >= m){
                System.out.println(i);
                break;
            }
        }
    }
}
