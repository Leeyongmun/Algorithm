import java.util.Scanner;

public class Main {
    static int n, m, t;
    static int[][] a;
    static int[][] tmp;
    static int[] dy1 = {0, -1, 0, 1};
    static int[] dx1 = {1, 0, -1, 0};
    static int[] dy2 = {0, 1, 0, -1};
    static int[] dx2 = {1, 0, -1 ,0};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();
        a = new int[n][m];
        tmp = new int[n][m];
        Pair clean = new Pair(-1, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
                if(a[i][j] == -1){
                    clean = new Pair(i, j);
                }
            }
        }
        while(t-- > 0){
            for(int i = 0; i < n; i++){
                tmp[i] = a[i].clone();
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(a[i][j] == -1 || a[i][j] == 0) continue;
                    int cnt = 0;
                    int div = a[i][j] / 5;
                    for(int dir = 0; dir < 4; dir++){
                        int ny = i + dy1[dir];
                        int nx = j + dx1[dir];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m || tmp[ny][nx] == -1) continue;
                        cnt++;
                        tmp[ny][nx] += div;
                    }
                    tmp[i][j] -= cnt * div;
                }
            }
            run(clean.y - 1, clean.x, 1);
            run(clean.y, clean.x, 2);
            for(int i = 0; i < n; i++){
                a[i] = tmp[i].clone();
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == -1) continue;
                ret += a[i][j];
            }
        }
        System.out.println(ret);
    }

    private static void run(int y, int x, int d){
        int[] dy = d == 1 ? dy1 : dy2;
        int[] dx = d == 1 ? dx1 : dx2;
        int idx = 0;
        int sy = y;
        int prev = 0;
        while(idx < 4){
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if(d == 1){
                if(ny < 0 || nx < 0 || ny > sy || nx >= m){
                    idx++;
                    continue;
                }
            }else{
                if(ny < sy || nx < 0 || ny >= n || nx >= m){
                    idx++;
                    continue;
                }
            }
            if(ny == sy && nx == 0) break;

            int cur = tmp[ny][nx];
            tmp[ny][nx] = prev;
            prev = cur;
            y = ny;
            x = nx;
        }
        tmp[sy][0] = -1;
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
