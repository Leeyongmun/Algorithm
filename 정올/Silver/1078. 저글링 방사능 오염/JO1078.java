import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class JO1078 {
    static int n, m;
    static int sy, sx;
    static int cnt = 0;
    static int mx = 0;
    static int[][] a;
    static int[][] visited;
    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, 1, 0, -1 };

    static class Pair {
        int y, x;

        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        a = new int[n + 1][m + 1];
        visited = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            Arrays.fill(visited[i], -1);
        }

        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            for (int j = 1; j <= m; j++) {
                a[i][j] = s.charAt(j - 1) - '0';
                if (a[i][j] == 1)
                    cnt++;
            }
        }

        st = new StringTokenizer(br.readLine());

        sx = Integer.parseInt(st.nextToken());
        sy = Integer.parseInt(st.nextToken());

        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(sy, sx));
        visited[sy][sx] = 0;

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            cnt--;

            mx = Math.max(mx, visited[y][x]);

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 1 || nx < 1 || ny > n || nx > m)
                    continue;
                if (a[ny][nx] == 0 || visited[ny][nx] != -1)
                    continue;
                q.offer(new Pair(ny, nx));
                visited[ny][nx] = visited[y][x] + 1;
            }
        }

        System.out.println(mx + 3);
        System.out.println(cnt);
    }
}
