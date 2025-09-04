import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int T, n;
    static int[][] a;
    static int[][] dist;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int t = 1; ; t++){
            n = sc.nextInt();
            if(n == 0) return;
            a = new int[n][n];
            dist = new int[n][n];
            for(int i = 0; i < n; i++){
                Arrays.fill(dist[i], 987654321);
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            PriorityQueue<Data> pq = new PriorityQueue<>(Comparator.comparing(e -> e.w));
            pq.offer(new Data(0, 0, a[0][0]));
            while(!pq.isEmpty()){
                Data cur = pq.poll();
                int y = cur.y;
                int x = cur.x;
                int w = cur.w;
                if(dist[y][x] < w) continue;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    int nd = w + a[ny][nx];
                    if(dist[ny][nx] > nd){
                        dist[ny][nx] = nd;
                        pq.offer(new Data(ny, nx, nd));
                    }
                }
            }
            System.out.println("Problem " + t + ": " + dist[n - 1][n - 1]);
        }
    }

    static class Data{
        int y, x, w;
        Data(int y, int x, int w){
            this.y = y;
            this.x = x;
            this.w = w;
        }
    }
}
