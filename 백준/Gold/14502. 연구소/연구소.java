import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] a;
    static int[][] b;
    static ArrayList<Pair> virus = new ArrayList<>();
    static ArrayList<Pair> empty = new ArrayList<>();
    static ArrayList<Pair> tmp = new ArrayList<>();
    static boolean[][] visited;
    static int[] dy = { -1, 0, 1, 0};
    static int[] dx = { 0, 1, 0, -1};
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
                if(a[i][j] == 0){
                    empty.add(new Pair(i, j));
                }
                else if(a[i][j] == 2){
                    virus.add(new Pair(i, j));
                }
            }
        }
        solve(0);
        System.out.println(ret);
    }

    private static void solve(int now){
        if(tmp.size() == 3){
            b = new int[n][m];
            for(int i = 0; i < n; i++){
                b[i] = a[i].clone();
            }
            for(Pair p : tmp){
                b[p.y][p.x] = 1;
            }
            visited = new boolean[n][m];
            for(Pair p : virus){
                dfs(p.y, p.x);
            }
            int sum = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(b[i][j] == 0){
                        sum++;
                    }
                }
            }
            ret = Math.max(ret, sum);
            return;
        }
        for(int i = now; i < empty.size(); i++){
            tmp.add(empty.get(i));
            solve(i + 1);
            tmp.remove(tmp.size() - 1);
        }
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        b[y][x] = 2;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || b[ny][nx] != 0) continue;
            dfs(ny, nx);
        }
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
