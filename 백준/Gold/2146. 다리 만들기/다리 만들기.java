import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static boolean[][] visited;
    static int cnt = 0;
    static int ret = 987654321;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited = new boolean[n][n];
                if(a[i][j] != 0){
                    Queue<Pair> q = new ArrayDeque<>();
                    q.offer(new Pair(i, j));
                    visited[i][j] = true;
                    int t = -1;
                    while(!q.isEmpty()){
                        boolean flag = false;
                        int size = q.size();
                        t++;
                        for(int l = 0; l < size; l++){
                            Pair p = q.poll();
                            int y = p.y;
                            int x = p.x;
                            for(int dir = 0; dir < 4; dir++){
                                int ny = y + dy[dir];
                                int nx = x + dx[dir];
                                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                                if(a[ny][nx] == a[i][j]) continue;
                                if(visited[ny][nx]) continue;
                                if(a[ny][nx] == 0){
                                    q.offer(new Pair(ny, nx));
                                    visited[ny][nx] = true;
                                }
                                else{
                                    ret = Math.min(ret, t);
                                    flag = true;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                }
            }
        }
        System.out.println(ret);
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        a[y][x] = cnt;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            dfs(ny, nx);
        }
    }
}

class Pair{
    int y, x;
    Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}
