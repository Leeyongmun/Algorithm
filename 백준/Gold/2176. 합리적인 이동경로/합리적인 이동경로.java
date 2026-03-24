import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Node{
        int to, cost;
        Node(int to, int cost){
            this.to = to;
            this.cost = cost;
        }
    }

    static int n, m;
    static ArrayList<Node>[] graph;
    static int[] dist, dp;
    static PriorityQueue<Node> pq = new PriorityQueue<>((a, b) ->{
        return a.cost - b.cost;
    });

    static int dfs(int cur){
        if(cur == 2) return 1;
        if(dp[cur] != -1) return dp[cur];
        dp[cur] = 0;
        for(Node next : graph[cur]){
            if(dist[next.to] < dist[cur]){
                dp[cur] += dfs(next.to);
            }
        }
        return dp[cur];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        graph = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        dist = new int[n + 1];
        dp = new int[n + 1];

        Arrays.fill(dist, 987654321);
        Arrays.fill(dp, -1);

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[from].add(new Node(to, cost));
            graph[to].add(new Node(from, cost));
        }

        pq.add(new Node(2, 0));
        dist[2] = 0;
        while(!pq.isEmpty()){
            Node now = pq.poll();
            int cur = now.to;
            int cost = now.cost;
            if(dist[cur] < cost) continue;
            for(Node next : graph[cur]){
                int nCost = next.cost + cost;
                if(dist[next.to] > nCost){
                    dist[next.to] = nCost;
                    pq.add(new Node(next.to, nCost));
                }
            }
        }
        System.out.println(dfs(1));
    }
}
