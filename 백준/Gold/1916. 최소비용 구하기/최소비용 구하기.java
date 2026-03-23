import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static ArrayList<Node>[] graph;
    static int[] dist;
    static final int INF = 1000000010;

    static class Node implements Comparable<Node>{
        int to, cost;
        
        private Node(int to, int cost){
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o){
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        graph = new ArrayList[n + 1];
        dist = new int[n + 1];
        Arrays.fill(dist, INF);
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[from].add(new Node(to, cost));
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(cur.to == end){
                System.out.println(cur.cost);
                break;
            }
            if(dist[cur.to] < cur.cost) continue;
            for(Node next : graph[cur.to]){
                int nCost = cur.cost + next.cost;
                if(dist[next.to] > nCost){
                    dist[next.to] = nCost;
                    pq.add(new Node(next.to, nCost));
                }
            }
        }
    }
}
