import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n;
    static char[][] a;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static boolean[][] visited; 

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new char[n][n];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < n; j++){
                a[i][j] = s.charAt(j);
            }
        }
        visited = new boolean[n][n];
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                bfs(i, j);
                cnt_a++;
            }
        }
        visited = new boolean[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 'G') a[i][j] = 'R';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                bfs(i, j);
                cnt_b++;
            }
        }
        System.out.println(cnt_a + " " + cnt_b);
    }

    private static void bfs(int y, int x){
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(y, x));
        visited[y][x] = true;
        while(!q.isEmpty()){
            Pair p = q.poll();
            for(int i = 0; i < 4; i++){
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx] || a[ny][nx] != a[y][x]) continue;
                q.offer(new Pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}

class Pair{
    int y;
    int x;
    Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}
