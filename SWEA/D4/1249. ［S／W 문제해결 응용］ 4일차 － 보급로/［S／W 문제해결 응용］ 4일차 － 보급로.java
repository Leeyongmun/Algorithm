import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    static int T, n;
    static int[][] a;
    static int[][] dist;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            dist = new int[n][n];
            visited = new boolean[n][n];
            a = new int[n][n];
            for(int i = 0; i < n; i++){
                String s = sc.next();
                for(int j = 0; j < n; j++){
                    a[i][j] = s.charAt(j) - '0';
                }
            }
            for(int i = 0; i < n; i++){
                Arrays.fill(dist[i], 987654321);
            }
            PriorityQueue<Data> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.w));
            pq.offer(new Data(0, 0, 0));
            while(!pq.isEmpty()){
                Data now = pq.poll();
                int y = now.y;
                int x = now.x;
                int w = now.w;
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
            System.out.println("#" + t + " " + dist[n-1][n-1]);
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
