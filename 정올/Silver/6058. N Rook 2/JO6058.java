import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class JO6058 {
    static int n;
    static char[][] a;
    static boolean[] check;
    static int ret = 0;

    static void solve(int cur) {
        if (cur == n) {
            ret++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (a[cur][i] == '#' || check[i] == true)
                continue;
            check[i] = true;
            solve(cur + 1);
            check[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new char[n][n];
        check = new boolean[n];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j);
            }
        }

        solve(0);

        System.out.println(ret);
    }
}
