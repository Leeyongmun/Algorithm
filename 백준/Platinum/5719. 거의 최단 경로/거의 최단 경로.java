import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int s, e;
    static ArrayList<Node>[] graph;
    static ArrayList<Integer>[] prev; // 역추적을 위한 prev배열
    static boolean[][] removed; // 제거된 간선을 재방문하지 않기 위한 배열
    static int[] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            if(n == 0 && m == 0) break;
            graph = new ArrayList[n];
            prev = new ArrayList[n];
            removed = new boolean[n][n];
            for(int i = 0; i < n; i++){
                graph[i] = new ArrayList<>();
                prev[i] = new ArrayList<>();
            }
            dist = new int[n];
            Arrays.fill(dist, 987654321);
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                graph[from].add(new Node(to, w));
            }

            dijkstra(); // 최단거리를 먼저 찾는다.
            if(dist[e] == 987654321){
                System.out.println(-1);
                continue;
            }
            removeShortRoute(); // 최단거리경로를 removed 배열에 넣어 재방문하지 않도록 한다.
            dijkstra(); // 다시 최단거리를 찾으면 거의 최단경로 나옴
            System.out.println((dist[e] == 987654321 ? -1 : dist[e]));
        }
    }

    private static void dijkstra(){
        dist = new int[n];
        Arrays.fill(dist, 987654321);
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.w));
        dist[s] = 0;
        pq.offer(new Node(s, 0));

        while(!pq.isEmpty()){
            Node now = pq.poll();
            int cur = now.to;
            int w = now.w;
            if(dist[cur] < w) continue;
            for(Node p : graph[cur]){
                int next = p.to;
                int nc = w + p.w;
                if(removed[cur][next]) continue; // 제거된 경로면 continue
                if(dist[next] > nc){
                    dist[next] = nc;
                    pq.offer(new Node(next, nc));
                    // 최단경로가 갱신이 되었으므로 기존에있던 리스트 초기화후 다시 넣기
                    prev[next].clear(); 
                    prev[next].add(cur);
                }
                else if(dist[next] == nc){
                    // 최단경로가 여러개일 수 도있기 때문에 거리가 같으면 pq에는 넣지 않더라도 prev에 넣어준다.
                    prev[next].add(cur);
                }
            }
        }
    }

    // 
    private static void removeShortRoute(){
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[n];
        q.add(e); // 큐에 e를 넣고 e부터 역으로 경로를 추적
        visited[e] = true;

        //경로를 역으로 추적하면서 최단거리 경로를 삭제 처리
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int p : prev[cur]){
                if(!removed[p][cur]){
                    removed[p][cur] = true;
                    if(!visited[p]){
                        visited[p] = true;
                        q.add(p);
                    }
                }
            }
        }
    }

    static class Node{
        int to, w;
        Node(int to, int w){
            this.to = to;
            this.w = w;
        }
    }
}
