import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, x;
    static int[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        a = new int[n + 1];

        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        int mx = 0;
        int cnt = 0;

        for (int i = 1; i <= x; i++) {
            sum += a[i];
        }

        mx = sum;
        cnt = 1;

        for (int i = x + 1; i <= n; i++) {
            sum -= a[i - x];
            sum += a[i];
            if (mx < sum) {
                mx = sum;
                cnt = 1;
            } else if (mx == sum) {
                cnt++;
            }
        }

        if (mx == 0) {
            System.out.println("SAD");
            return;
        }

        System.out.println(mx);
        System.out.println(cnt);
    }
}
