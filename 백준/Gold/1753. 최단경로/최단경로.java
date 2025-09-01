import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int start;
    static int[] dist;
    static ArrayList<Edge>[] edge;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        start = sc.nextInt();
        dist = new int[n + 1];
        edge = new ArrayList[n + 1];
        Arrays.fill(dist, 987654321);
        for(int i = 1; i <= n; i++){
            edge[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            int cost = sc.nextInt();
            edge[from].add(new Edge(to, cost));
        }
        dist[start] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.cost));
        pq.offer(new Edge(start, 0));

        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            int to = cur.to;
            int cost = cur.cost;
            if(cost > dist[to]) continue;
            for(Edge e : edge[to]){
                if(dist[e.to] > cost + e.cost){
                    dist[e.to] = cost + e.cost;
                    pq.offer(new Edge(e.to, dist[e.to]));
                }
            }
        }

        for(int i = 1; i <= n; i++){
            System.out.println(dist[i] == 987654321 ? "INF" : dist[i]);
        }
        
    }

    static class Edge{
        int to, cost;
        Edge(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }
}
