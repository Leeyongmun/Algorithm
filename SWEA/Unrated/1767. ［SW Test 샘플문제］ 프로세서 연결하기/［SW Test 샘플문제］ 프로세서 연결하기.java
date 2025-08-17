import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    static int T, n;
    static int[][] a;
    static boolean[][] visited;
    static ArrayList<Pair> core = new ArrayList<>();
    static int ret, len_cnt;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            core.clear();
            ret = 0;
            len_cnt = 987654321;
            n = sc.nextInt();
            a = new int[n][n];
            visited = new boolean[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                    if(a[i][j] == 1){
                        if(i == 0 || j == 0 || i == n - 1 || j == n - 1) continue;
                        core.add(new Pair(i, j));
                    }
                }
            }
            solve(0, 0, 0);
            System.out.println("#" + t + " " + len_cnt);
        }
    }

    private static void solve(int cnt, int len, int con){
        if(cnt == core.size()){
            if(con >= ret){
                if(con > ret) {
                    len_cnt = len;
                    ret = con;
                }
                else len_cnt = Math.min(len_cnt, len);
            }
            return;
        }
        if(ret > con + core.size() - cnt) return;
        int y = core.get(cnt).y;
        int x = core.get(cnt).x;
        for(int j = 0; j < 4; j++){
            int tmp = check(y, x, j);
            if(tmp == -1) continue;
            doVisit(y, x, j);
            solve(cnt + 1, len + tmp, con + 1);
            undoVisit(y, x, j);
        }
        solve(cnt + 1, len, con);
    }

    private static int check(int y, int x, int dir){
        int len = 0;
        int ny = y;
        int nx = x;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n){
                return len;
            }
            if(visited[ny][nx] || a[ny][nx] == 1){
                return -1;
            }
            len++;
        }
    }

    private static void doVisit(int y, int x, int dir){
        int ny = y;
        int nx = x;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n){
                return;
            }
            visited[ny][nx] = true;
        }
    }

    private static void undoVisit(int y, int x, int dir){
        int ny = y;
        int nx = x;
        while(true){
            ny += dy[dir];
            nx += dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n){
                return;
            }
            visited[ny][nx] = false;
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
