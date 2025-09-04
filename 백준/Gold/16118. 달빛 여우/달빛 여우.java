import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static ArrayList<Edge>[] edge;
    static int[] dist;
    static int[][] dist2;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        edge = new ArrayList[n + 1];
        dist = new int[n + 1];
        dist2 = new int[2][n + 1];
        Arrays.fill(dist, 987654321);
        for(int i = 1; i <= n; i++){
            edge[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edge[from].add(new Edge(to, 2 * cost));
            edge[to].add(new Edge(from, 2 * cost));
        }
        PriorityQueue<Edge> pq1 = new PriorityQueue<>(Comparator.comparingInt(e -> e.cost));
        dist[1] = 0;
        pq1.offer(new Edge(1, 0));
        while(!pq1.isEmpty()){
            Edge now = pq1.poll();
            int cost = now.cost;
            int cur = now.to;
            if(dist[cur] < cost) continue;
            for(Edge e : edge[cur]){
                int nd = cost + e.cost;
                if(dist[e.to] > nd){
                    dist[e.to] = nd;
                    pq1.offer(new Edge(e.to, nd));
                } 
            }
        }
        PriorityQueue<Data> pq2 = new PriorityQueue<>(Comparator.comparingInt(e -> e.cost));
        Arrays.fill(dist2[0], 987654321);
        Arrays.fill(dist2[1], 987654321);
        dist2[0][1] = 0;
        pq2.offer(new Data(1, 0, 0));
        while(!pq2.isEmpty()){
            Data now = pq2.poll();
            int cost = now.cost;
            int cur = now.to;
            int cnt = now.cnt;
            if(dist2[cnt][cur] < cost) continue;
            for(Edge e : edge[cur]){
                if(cnt % 2 == 0){
                    int nd = cost + e.cost / 2;
                    if(dist2[1][e.to] > nd){
                        dist2[1][e.to] = nd;
                        pq2.offer(new Data(e.to, nd, 1));
                    }
                }
                else {
                    int nd = cost + e.cost * 2;
                    if(dist2[0][e.to] > nd){
                        dist2[0][e.to] = nd;
                        pq2.offer(new Data(e.to, nd, 0));
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 1; i <= n; i++){
            int dist_wolf = Math.min(dist2[0][i], dist2[1][i]);
            if(dist[i] < dist_wolf) ret++;
        }
        System.out.println(ret);
    }

    static class Edge{
        int to, cost;
        Edge(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }

    static class Data{
        int to, cost, cnt;
        Data(int to, int cost, int cnt){
            this.to = to;
            this.cost = cost;
            this.cnt = cnt;
        }
    }
}
