import java.util.Scanner;

public class Solution {
    static int T, n;
    static int[][] a;
    static int[] dy ={-1, -1, 1, 1};
    static int[] dx = {-1, 1, 1, -1};
    static int ret = -1;
    static boolean[] used;
    static boolean[][] visited;
    static int sy, sx;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            ret = -1;
            n = sc.nextInt();
            a = new int[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    used = new boolean[101];
                    visited = new boolean[n][n];
                    sy = i;
                    sx = j;
                    used[a[i][j]] = true;
                    visited[i][j] = true;
                    dfs(i, j, 0, 0, 1);
                    used[a[i][j]] = false;
                    visited[i][j] = false;
                }
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static void dfs(int y, int x, int dir, int turn, int sum){
        for(int d = 0; d < 2; d++){
            int ndir = dir + d;
            if(ndir >= 4) continue;
            int nturn = turn + (d == 1 ? 1 : 0);
            if(nturn > 3) continue;
            if(d == 1 && sum == 1) continue;
            int ny = y + dy[ndir];
            int nx = x + dx[ndir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

            if(ny == sy && nx == sx){
                if(nturn == 3 && sum >= 4) ret = Math.max(ret, sum);
                continue;
            }
            if(visited[ny][nx]) continue;
            if(used[a[ny][nx]]) continue;

            visited[ny][nx] = true;
            used[a[ny][nx]] = true;

            dfs(ny, nx, ndir, nturn, sum + 1);

            visited[ny][nx] = false;
            used[a[ny][nx]] = false;
        }
    }
}
