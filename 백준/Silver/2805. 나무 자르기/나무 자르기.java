import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        a = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        int l = 0;
        int r = 1000000000;

        int ret = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            long sum = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] <= mid)
                    continue;
                sum += (a[i] - mid);
            }
            if (sum < m) {
                r = mid - 1;
            } else {
                ret = mid;
                l = mid + 1;
            }
        }
        System.out.println(ret);
    }
}
