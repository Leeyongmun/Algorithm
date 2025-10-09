import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a;
    static ArrayList<Pair> list = new ArrayList<>();
    static ArrayList<Pair> virus = new ArrayList<>();
    static int[] dy = { -1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int ret = 0;
    
    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

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
                list.add(new Pair(i, j));
                if(a[i][j] == 2){
                    virus.add(new Pair(i, j));
                }
            }
        }
        solve(0, 0);
        System.out.println(ret);
    }

    private static void solve(int cnt, int now){
        if(cnt == 3){
            bfs();
            return;
        }
        for(int i = now; i < list.size(); i++){
            Pair cur = list.get(i);
            if(a[cur.y][cur.x] != 0) continue;
            a[cur.y][cur.x] = 1;
            solve(cnt + 1, now + 1);
            a[cur.y][cur.x] = 0;
        }
    }

    private static void bfs(){
        int[][] b = new int[n][m];
        for(int i = 0; i < n; i++){
            b[i] = a[i].clone();
        }
        Queue<Pair> q = new ArrayDeque<>();
        for(int i = 0; i < virus.size(); i++){
            q.offer(virus.get(i));
        }
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(b[ny][nx] != 0) continue;
                b[ny][nx] = 2;
                q.offer(new Pair(ny, nx));
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(b[i][j] == 0){
                    sum++;
                }
            }
        }
        ret = Math.max(sum, ret);
    }
}
