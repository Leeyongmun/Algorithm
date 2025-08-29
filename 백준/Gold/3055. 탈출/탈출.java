import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static char[][] map;
    static ArrayList<Pair> water = new ArrayList<>();
    static int[][] a;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static Pair beaver, cave;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[n][m];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < m; j++){
                map[i][j] = s.charAt(j);
                if(map[i][j] == '*'){
                    water.add(new Pair(i, j));
                }
                if(map[i][j] == 'S'){
                    beaver = new Pair(i, j);
                }
                if(map[i][j] == 'D'){
                    cave = new Pair(i, j);
                }
            }
        }
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            Arrays.fill(a[i], 987654321);
        }
        water_bfs();
        int[][] visited = new int[n][m];
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(beaver);
        visited[beaver.y][beaver.x] = 1;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            if(y == cave.y && x == cave.x) break;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(map[ny][nx] == 'X' || visited[ny][nx] != 0) continue;
                if(a[ny][nx] > visited[y][x] + 1){
                    q.offer(new Pair(ny, nx));
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }
        
        System.out.println(visited[cave.y][cave.x] != 0 ? visited[cave.y][cave.x] - 1 : "KAKTUS");
    }

    private static void water_bfs(){
        Queue<Pair> q = new ArrayDeque<>();
        for(Pair p : water){
            q.offer(p);
            a[p.y][p.x] = 1;
        }
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(map[ny][nx] == 'X') continue;
                if(map[ny][nx] == 'D') continue;
                if(a[ny][nx] != 987654321) continue;
                q.offer(new Pair(ny, nx));
                a[ny][nx] = a[y][x] + 1;
            }
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
