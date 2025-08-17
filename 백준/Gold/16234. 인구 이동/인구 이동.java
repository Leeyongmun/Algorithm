import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, l, r;
    static int[][] a;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int sum = 0, ret = 0;
    static boolean flag = false;
    static ArrayList<Pair> tmp = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        l = sc.nextInt();
        r = sc.nextInt();
        a = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
            }
        }
        while(true){
            flag = false;
            visited = new boolean[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(visited[i][j]) continue;
                    sum = a[i][j];
                    tmp.add(new Pair(i, j));
                    dfs(i, j);
                    int cnt = tmp.size();
                    if(cnt > 1) flag = true;
                    for(Pair p : tmp){
                        a[p.y][p.x] = sum / cnt;
                    }
                    tmp.clear();
                }
            }
            if(!flag) break;
            ret++;
        }
        System.out.println(ret);
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx]) continue;
            int diff = Math.abs(a[y][x] - a[ny][nx]);
            if(diff >= l && diff <= r){
                sum += a[ny][nx];
                tmp.add(new Pair(ny, nx));
                dfs(ny, nx);
            }
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