import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] a;
    static int[][][] dist;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n][m];
        dist = new int[n][m][2];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < m; j++){
                a[i][j] = s.charAt(j) - '0';
            }
        }
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(0, 0, 0));
        dist[0][0][0] = 1;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            int broken = cur.broken;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[ny][nx] == 0){
                    if(dist[ny][nx][broken] == 0 || dist[ny][nx][broken] > dist[y][x][broken] + 1){
                        dist[ny][nx][broken] = dist[y][x][broken] + 1;
                        q.offer(new Pair(ny, nx, broken));
                    } 
                }
                if(a[ny][nx] == 1 && broken == 0){
                    if(dist[ny][nx][1] == 0 || dist[ny][nx][1] > dist[y][x][broken] + 1){
                        dist[ny][nx][1] = dist[y][x][broken] + 1;
                        q.offer(new Pair(ny, nx, 1));
                    }
                }
            }
        }
        int ret = 987654321;
        for(int i = 0; i < 2; i++){
            if(dist[n - 1][m - 1][i] != 0){
                ret = Math.min(ret, dist[n - 1][m - 1][i]);
            }
        }
        System.out.println(ret == 987654321 ? -1 : ret);
    }

    static class Pair{
        int y, x, broken;
        Pair(int y, int x, int broken){
            this.y = y;
            this.x = x;
            this.broken = broken;
        }
    }
}
