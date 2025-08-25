import java.util.Scanner;

public class Solution {
    static int T, n;
    static char[][] a;
    static int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            visited = new boolean[n][n];
            a = new char[n][n];
            int ret = 0;
            for(int i = 0; i < n; i++){
                String s = sc.next();
                for(int j = 0; j < n; j++){
                    a[i][j] = s.charAt(j);
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(a[i][j] == '.' && !visited[i][j]){
                        if(check(i,j)) {
                            dfs(i, j);
                            ret++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(!visited[i][j] && a[i][j] == '.') ret++;
                }
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static boolean check(int y, int x){
        for(int dir = 0; dir < 8; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(a[ny][nx] == '*') return false;
        }
        return true;
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        if(check(y, x)){
            for(int i = 0; i < 8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited[ny][nx]) continue;
                dfs(ny, nx);
            }
        }
    }
}
