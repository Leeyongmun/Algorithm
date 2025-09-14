import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            String s = br.readLine();
            for(int j = 0; j < m; j++){
                a[i][j] = s.charAt(j) - '0';
            }
        }
        int[][] visited = new int[n][m];
        Deque<Pair> dq = new ArrayDeque<>();
        dq.addFirst(new Pair(0, 0));
        visited[0][0] = 1;
        while(!dq.isEmpty()){
            Pair cur = dq.poll();
            int y = cur.y;
            int x = cur.x;
            if(y == n - 1 && x == m - 1) break;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited[ny][nx] != 0) continue;
                if(a[ny][nx] == 1){
                    dq.add(new Pair(ny, nx));
                    visited[ny][nx] = visited[y][x] + 1;
                }
                else if(a[ny][nx] == 0){
                    dq.addFirst(new Pair(ny, nx));
                    visited[ny][nx] = visited[y][x];
                }
            }
        }
        System.out.println(visited[n - 1][m - 1] - 1);
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
