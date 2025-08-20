import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] a;
    static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            m = sc.nextInt();
            n = sc.nextInt();
            if(n == 0 && m == 0) break;
            a = new int[n][m];
            boolean[][] visited = new boolean[n][m];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            Queue<Pair> q = new ArrayDeque<>();
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(a[i][j] == 1 && !visited[i][j]){
                        cnt++;
                        q.offer(new Pair(i, j));
                        visited[i][j] = true;
                        while(!q.isEmpty()){
                            Pair p = q.poll();
                            int y = p.y;
                            int x = p.x;
                            for(int dir = 0; dir < 8; dir++){
                                int ny = y + dy[dir];
                                int nx = x + dx[dir];
                                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                                if(visited[ny][nx]) continue;
                                if(a[ny][nx] != 1) continue;
                                q.offer(new Pair(ny, nx));
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
            }
            System.out.println(cnt);
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
