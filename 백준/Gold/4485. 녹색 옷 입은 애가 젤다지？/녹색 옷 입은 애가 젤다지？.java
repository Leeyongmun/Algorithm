import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] a;
    static int[][] dist;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int t = 1; ; t++){
            n = Integer.parseInt(br.readLine());
            if(n == 0) return;
            a = new int[n][n];
            dist = new int[n][n];
            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; j++){
                    a[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int i = 0; i < n; i++){
                Arrays.fill(dist[i], 987654321);
            }
            PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.w));
            pq.offer(new Node(0, 0, a[0][0]));
            while(!pq.isEmpty()){
                Node cur = pq.poll();
                int y = cur.y;
                int x = cur.x;
                int w = cur.w;
                if(dist[y][x] < w) continue;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    int nw = w + a[ny][nx];
                    if(dist[ny][nx] > nw){
                        dist[ny][nx] = nw;
                        pq.offer(new Node(ny, nx, nw));
                    }
                }
            }
            System.out.println("Problem " + t + ": " + dist[n - 1][n - 1]);
        }
    }

    static class Node{
        int y, x, w;
        Node(int y, int x ,int w){
            this.y = y;
            this.x = x;
            this.w = w;
        }
    }
}
