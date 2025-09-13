import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, k;
    static ArrayList<Pair>[] graph;
    static long[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        graph = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        dist = new long[n + 1][k + 1];
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[from].add(new Pair(to, w));
            graph[to].add(new Pair(from, w));
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dist[i][j] = 100000000000L;
            }
        }
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingLong(e -> e.w));
        pq.offer(new Node(1, 0, 0));
        while(!pq.isEmpty()){
            Node now = pq.poll();
            int cur = now.to;
            int pave = now.pave;
            long w = now.w;
            if(dist[cur][pave] < w) continue;
            for(Pair p : graph[cur]){
                int next = p.to;
                long nCost = p.w;
                if(pave < k){
                    if(dist[next][pave + 1] > w){
                        dist[next][pave + 1] = w;
                        pq.offer(new Node(next, pave + 1, w));
                    }
                }
                if(dist[next][pave] > w + nCost){
                    dist[next][pave] = w + nCost;
                    pq.offer(new Node(next, pave, w + nCost));
                }
            }
        }
        long ret = 100000000000L;
        for(int i = 0; i <= k; i++){
            ret = Math.min(ret, dist[n][i]);
        }
        System.out.println(ret);
    }

    static class Pair{
        int to;
        long w;
        Pair(int to, long w){
            this.to = to;
            this.w = w;
        }
    }

    static class Node{
        int to, pave;
        long w;
        Node(int to, int pave, long w){
            this.to = to;
            this.pave = pave;
            this.w = w;
        }
    }
}
