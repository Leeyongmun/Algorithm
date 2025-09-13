import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a, dp;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        a = new int[n + 1][m + 1];
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= m; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp = new int[n + 1][m + 1];
        dp[1][1] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= m; j++){
                if(a[i][j] == 1) dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                else dp[i][j] = 0;
            }
        }
        System.out.println(dp[n][m] == 1 ? "Yes" : "No");
    }
}
