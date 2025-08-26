import java.util.Scanner;

public class Solution {
    static int T, n, m;
    static char[][] a;
    static int mask = 0;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            mask = 0;
            ret = 0;
            a = new char[n][m];
            for(int i = 0; i < n; i++){
                String s = sc.next();
                for(int j = 0; j < m; j++){
                    a[i][j] = s.charAt(j);
                }
            }
            dfs(0, 0, 1);
            System.out.println("#" + t + " " + ret);
        }
    }

    private static void dfs(int y, int x, int cnt){
        ret = Math.max(cnt, ret);
        mask |= (1 << ((a[y][x]) - 'A'));
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if((mask & (1 << (a[ny][nx] - 'A'))) != 0) continue;
            dfs(ny, nx, cnt + 1);
        }
        mask &= ~(1 << ((a[y][x]) - 'A'));
    }
}
