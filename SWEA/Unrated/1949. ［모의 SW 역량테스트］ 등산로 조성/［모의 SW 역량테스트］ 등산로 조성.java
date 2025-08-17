import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    static int T, n, k;
    static int[][] a;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static ArrayList<Pair> mx = new ArrayList<>();
    static boolean[][] visited;
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            ret = 0;
            mx.clear();
            n = sc.nextInt();
            k = sc.nextInt();
            a = new int[n][n];
            int max = -1;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                    max = Math.max(max, a[i][j]);
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(a[i][j] == max){
                        mx.add(new Pair(i, j));
                    }
                }
            }
            for(Pair p : mx){
                int y = p.y;
                int x = p.x;
                visited = new boolean[n][n];
                dfs(y, x, 1, false);
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static void dfs(int y, int x, int cnt, boolean flag){
        visited[y][x] = true;
        ret = Math.max(ret, cnt);
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx]) continue;
            if(flag && a[y][x] <= a[ny][nx]) continue;
            int tmp = 0;
            if(a[y][x] <= a[ny][nx] && !flag){
                if(a[ny][nx] - k < a[y][x]){
                    tmp = a[ny][nx];
                    a[ny][nx] = a[y][x] - 1;
                    dfs(ny, nx, cnt + 1, true);
                    a[ny][nx] = tmp;
                }
            }
            if(a[ny][nx] < a[y][x]){ 
                dfs(ny, nx, cnt + 1, flag);
            }
        }
        visited[y][x] = false;
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
