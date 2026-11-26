import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, f;
    static int[][] a;
    static int y, x;
    static ArrayList<Passenger> p = new ArrayList<>();
    static boolean[] checked;
    static int[] dy = { -1, 0, 1, 0 };
    static int[] dx = { 0, 1, 0, -1 };

    static public class Passenger {
        int sy, sx, ey, ex;

        Passenger(int sy, int sx, int ey, int ex) {
            this.sy = sy;
            this.sx = sx;
            this.ey = ey;
            this.ex = ex;
        }
    }

    public static int get_distance(int sy, int sx, int ey, int ex) {
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[n + 1][n + 1];
        visited[sy][sx] = true;
        q.offer(new int[] { sy, sx, 0 });
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int y = cur[0];
            int x = cur[1];
            int d = cur[2];

            if (y == ey && x == ex) {
                return d;
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 1 || nx < 1 || ny > n || nx > n)
                    continue;
                if (a[ny][nx] == 1 || visited[ny][nx])
                    continue;
                q.offer(new int[] { ny, nx, d + 1 });
                visited[ny][nx] = true;
            }
        }
        return 987654321;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        f = Integer.parseInt(st.nextToken());

        a = new int[n + 1][n + 1];
        checked = new boolean[m];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());

        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int sy, sx, ey, ex;
            sy = Integer.parseInt(st.nextToken());
            sx = Integer.parseInt(st.nextToken());
            ey = Integer.parseInt(st.nextToken());
            ex = Integer.parseInt(st.nextToken());
            p.add(new Passenger(sy, sx, ey, ex));
        }

        p.sort((a, b) -> {
            if (a.sy != b.sy)
                return Integer.compare(a.sy, b.sy);
            return Integer.compare(a.sx, b.sx);
        });

        for (int i = 0; i < m; i++) {
            int mn = 987654321;
            int idx = -1;
            for (int j = 0; j < p.size(); j++) {
                if (!checked[j]) {
                    Passenger cur = p.get(j);
                    int dist = get_distance(y, x, cur.sy, cur.sx);
                    if (mn > dist) {
                        mn = dist;
                        idx = j;
                    }
                }
            }
            if (idx == -1 || f < mn) {
                System.out.println(-1);
                return;
            }
            Passenger passenger = p.get(idx);
            f -= mn;
            checked[idx] = true;

            int dist = get_distance(passenger.sy, passenger.sx, passenger.ey, passenger.ex);
            if (f < dist) {
                System.out.println(-1);
                return;
            }
            f -= dist;
            f += dist * 2;
            y = passenger.ey;
            x = passenger.ex;
        }

        System.out.println(f);
    }
}
