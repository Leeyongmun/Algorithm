import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static char[][] map;
    static int[][] water;
    static Pair beaver, end;
    static ArrayList<Pair> w = new ArrayList<>();
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static Queue<Pair> q = new ArrayDeque<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[n][m];
        water = new int[n][m];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < m; j++){
                map[i][j] = s.charAt(j);
                if(map[i][j] == '*') w.add(new Pair(i, j));
                else if(map[i][j] == 'S') beaver = new Pair(i, j);
                else if(map[i][j] == 'D') end = new Pair(i, j);
            }
        }
        bfs_water();
        int[][] visited = new int[n][m];
        visited[beaver.y][beaver.x] = 1;
        q.offer(beaver);
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            if(y == end.y && x == end.x) break;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(map[ny][nx] == 'X') continue;
                if(visited[ny][nx] != 0) continue;
                if(water[ny][nx] > visited[y][x] + 1) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.offer(new Pair(ny, nx));
                }
            }
        }
        System.out.println(visited[end.y][end.x] == 0 ? "KAKTUS" : visited[end.y][end.x] - 1);
    }

    private static void bfs_water(){
        for(int i = 0; i < n; i++){
            Arrays.fill(water[i], 987654321);
        }
        for(Pair p : w){
            q.offer(p);
            water[p.y][p.x] = 1;
        }
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;
                if(water[ny][nx] > water[y][x] + 1){
                    water[ny][nx] = water[y][x] + 1;
                    q.offer(new Pair(ny, nx));
                }
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
