import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int cnt = 1;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        visited = new boolean[n][m];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && a[i][j] == 1){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        ArrayList<Edge> edge = new ArrayList<>();
        
        // 모든 다리 구하기
        for(int i = 0; i < n; i++){
            boolean flag = false;
            int from_idx = -1;
            int from = -1;
            for(int j = 0; j < m; j++){
                if(!flag && a[i][j] != 0 && j + 1 < m && a[i][j + 1] == 0){
                    from = a[i][j];
                    from_idx = j;
                    flag = true;
                }
                else if(flag && a[i][j] != 0){
                    if(a[i][j] != from && j - from_idx > 2){
                        edge.add(new Edge(from, a[i][j], j - from_idx - 1));
                    }
                    from = a[i][j];
                    from_idx = j;
                }
            }
        }
        for(int j = 0; j < m; j++){
            boolean flag = false;
            int from_idx = -1;
            int from = -1;
            for(int i = 0; i < n; i++){
                if(!flag && a[i][j] != 0 && i + 1 < n && a[i + 1][j] == 0){
                    from = a[i][j];
                    from_idx = i;
                    flag = true;
                }
                else if(flag && a[i][j] != 0){
                    if(a[i][j] != from && i - from_idx > 2){
                        edge.add(new Edge(from, a[i][j], i - from_idx - 1));
                    }
                    from = a[i][j];
                    from_idx = i;
                }
            }
        }

        parent = new int[cnt];
        for(int i = 1; i < cnt; i++){
            parent[i] = i;
        }
        edge.sort(Comparator.comparingInt(e -> e.cost));
        int ret = 0;
        int count = 0;
        for(Edge e : edge){
            if(!merge(e.from, e.to)) continue;
            ret += e.cost;
            count++;
            if(count == cnt - 2) break; 
        }
        System.out.println(count == cnt - 2 ? ret : -1);
    }

    private static void bfs(int y, int x){
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(y, x));
        visited[y][x] = true;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int sy = cur.y;
            int sx = cur.x;
            a[sy][sx] = cnt;
            for(int i = 0; i < 4; i++){
                int ny = sy + dy[i];
                int nx = sx + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[ny][nx] == 0 || visited[ny][nx]) continue;
                q.offer(new Pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }

    private static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    private static boolean merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[x] = y;
        return true;
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    static class Edge{
        int from, to, cost;
        Edge(int from, int to, int cost){
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}
