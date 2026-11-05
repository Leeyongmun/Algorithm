import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class JO2751 {
    static int n, m;
    static int k;
    static ArrayList<Integer> a = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(br.readLine());

        if (k > n * m) {
            System.out.println(0);
            return;
        }

        int h = n;
        int w = m;
        int x = 1;
        int y = 1;

        while (w > 0 && h > 0) {
            int cnt;

            if (w == 1 || h == 1) {
                cnt = w * h;
            } else {
                cnt = 2 * w + 2 * h - 4;
            }

            if (k > cnt) {
                k -= cnt;
                w -= 2;
                h -= 2;
                x++;
                y++;
                continue;
            }

            if (w == 1) {
                y += k - 1;
            } else if (h == 1) {
                x += k - 1;
            } else if (k <= h) {
                y += k - 1;
            } else if (k <= h + w - 1) {
                y += h - 1;
                x += k - h;
            } else if (k <= h * 2 + w - 2) {
                x += w - 1;
                y += h - 1;
                y -= k - (h + w - 1);
            } else {
                x += w - 1;
                x -= k - (2 * h + w - 2);
            }

            System.out.println(x + " " + y);
            return;
        }
    }
}
