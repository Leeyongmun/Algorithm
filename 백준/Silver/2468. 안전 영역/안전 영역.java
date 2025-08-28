import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
                max = Math.max(max, a[i][j]);
            }
        }
        int ret = 1;
        for(int rain = 1; rain < max; rain++){
            visited = new boolean[n][n];
            int sum = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(a[i][j] == rain){
                        a[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(a[i][j] != 0 && !visited[i][j]){
                        dfs(i, j);
                        sum++;
                    }
                }
            }
            ret = Math.max(ret, sum);
        }
        System.out.println(ret);;
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] || a[ny][nx] == 0) continue;
            dfs(ny, nx);
        }
    }
}
