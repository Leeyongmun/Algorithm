import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Solution{
    static int T, k, n, m;
    static int[][] a;
    static int ret = 987654321;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            k = sc.nextInt();
            m = sc.nextInt();
            n = sc.nextInt();
            a = new int[n][m];
            ret = 987654321;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            int[][] b = new int[n][m];
            b = deepCopy(a);
            solve(0, b);
            System.out.println("#" + t + " " + ret);
        }
    }

    private static int[][] deepCopy(int[][] b){
        int[][] tmp = new int[n][m];
        for(int i = 0; i < n; i++){
            tmp[i] = b[i].clone();
        }
        return tmp;
    }

    private static void solve(int cnt, int[][] b){
        if(count(b) == 0){
            ret = 0;
            return;
        }
        if(cnt == k){
            int sum = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(b[i][j] != 0){
                        sum++;
                    }
                }
            }
            ret = Math.min(ret, sum);
            return;
        }
        for(int i = 0; i < m; i++){
            int row = brickCheck(b, i);
            if(row == -1) continue;
            int[][] tmp = deepCopy(b);
            boom(tmp, row, i);
            gravity(tmp);
            solve(cnt + 1, tmp);
        }
    }

    private static int count(int[][] b){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(b[i][j] != 0) cnt++;
            }
        }
        return cnt;
    }

    private static int brickCheck(int[][] b, int x){
        for(int i = 0; i < n; i++){
            if(b[i][x] != 0) return i;
        }
        return -1;
    }

    private static void boom(int[][] b, int y, int x){
        if(b[y][x] == 0) return;
        Queue<Data> q = new ArrayDeque<>();
        q.offer(new Data(y, x, b[y][x]));
        b[y][x] = 0;
        while(!q.isEmpty()){
            Data cur = q.poll();
            int cy = cur.y;
            int cx = cur.x;
            int power = cur.w;
            for(int dir = 0; dir < 4; dir++){
                for(int i = 1; i < power; i++){
                    int ny = cy + dy[dir] * i;
                    int nx = cx + dx[dir] * i;
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m) break;
                    if(b[ny][nx] == 0) continue;
                    if(b[ny][nx] > 1) q.offer(new Data(ny, nx, b[ny][nx]));
                    b[ny][nx] = 0;
                }
            }
        }
    }

    static private void gravity(int[][] b){
        for(int j = 0; j < m; j++){
            int idx = n - 1;
            for(int i = n -1; i >= 0; i--){
                if(b[i][j] != 0){
                    int num = b[i][j];
                    b[i][j] = 0;
                    b[idx--][j] = num;
                }
            }
        }
    }

    static class Data{
        int y, x, w;
        Data(int y, int x, int w){
            this.y = y;
            this.x = x;
            this.w = w;
        }
    }
}
