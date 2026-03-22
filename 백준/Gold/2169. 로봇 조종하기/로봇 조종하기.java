import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new int[n + 1][m + 1];
        dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[1][1] = a[1][1];
        for(int i = 2; i <= m; i++){
            dp[1][i] = dp[1][i - 1] + a[1][i];
        }

        for (int i = 2; i <= n; i++) {
            int[] left = new int[m + 1];
            int[] right = new int[m + 1];

            left[1] = dp[i - 1][1] + a[i][1];
            for (int j = 2; j <= m; j++) {
                left[j] = Math.max(dp[i - 1][j], left[j - 1]) + a[i][j];
            }

            right[m] = dp[i - 1][m] + a[i][m];
            for (int j = m - 1; j > 0; j--) {
                right[j] = Math.max(dp[i - 1][j], right[j + 1]) + a[i][j];
            }

            for (int j = 1; j <= m; j++) {
                dp[i][j] = Math.max(left[j], right[j]);
            }
        }

        System.out.println(dp[n][m]);
    }
}
