import java.io.*;
import java.util.*;

public class Main {
    static class Node{
        int to, cost;
        Node(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }

    static class Pair{
        int a, b;
        Pair(int a, int b){
            this.a = a;
            this.b = b;
        }
    }

    static int n, m;
    static ArrayList<Node>[] graph;
    static int[] dist;
    static int[] parent;
    static int ret = -1;

    static int dijkstra(int s, int e){
        Arrays.fill(dist, 987654321);
        dist[1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            return a.cost - b.cost;
        });
        pq.add(new Node(1, 0));

        while(!pq.isEmpty()){
            Node node = pq.poll();
            int cur = node.to;
            int cost = node.cost;
            if(dist[cur] < cost) continue;
            for(Node nNode : graph[cur]){
                int next = nNode.to;
                int nCost = cost + nNode.cost;
                if((cur == s && next == e) || (cur == e && next == s)) continue;
                if(dist[next] > nCost){
                    dist[next] = nCost;
                    pq.add(new Node(next, nCost));
                    parent[next] = cur;
                }
            }
        }

        return dist[n];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n + 1];
        dist = new int[n + 1];
        parent = new int[n + 1];
        Arrays.fill(parent, -1);
        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[from].add(new Node(to, cost));
            graph[to].add(new Node(from, cost));
        }

        dijkstra(-1, -1);
        ArrayList<Pair> path = new ArrayList<>();
        int cur = n;
        while(cur != -1){
            path.add(new Pair(cur, parent[cur]));
            cur = parent[cur];
        }

        for(Pair p : path){
            int x = dijkstra(p.a, p.b);
            ret = Math.max(ret, x);
        }
        System.out.println(ret);
    }
}
