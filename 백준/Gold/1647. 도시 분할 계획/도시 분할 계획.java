import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static ArrayList<Edge>[] graph;
    static int[] minEdge;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        graph = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        minEdge = new int[n + 1];
        Arrays.fill(minEdge, 987654321);
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            int cost = sc.nextInt();
            graph[from].add(new Edge(to, cost));
            graph[to].add(new Edge(from, cost));
        }
        boolean[] visited = new boolean[n + 1];
        minEdge[1] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.cost));
        pq.offer(new Edge(1, 0));
        int cnt = 0;
        int ret = 0;
        int max = -1;
        while(!pq.isEmpty() && cnt < n){
            Edge now = pq.poll();
            int cur = now.to;
            int cost = now.cost;
            if(visited[cur]) continue;
            visited[cur] = true;
            max = Math.max(max, cost);
            ret += cost;
            cnt++;
            for(Edge p : graph[cur]){
                int next = p.to;
                int w = p.cost;
                if(!visited[next] && minEdge[next] > w){
                    minEdge[next] = w;
                    pq.offer(p);
                }
            }
        }
        System.out.println(ret - max);
    }

    static class Edge{
        int to, cost;
        Edge(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }
}
