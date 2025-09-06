import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static char[][] map;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int ret = -1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[n][m];
        Pair jihun = new Pair(0, 0);
        ArrayList<Pair> fire = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < m; j++){
                map[i][j] = s.charAt(j);
                if(map[i][j] == 'J') jihun = new Pair(i, j);
                else if(map[i][j] == 'F') fire.add(new Pair(i, j));
            }
        }
        int[][] visited_j = new int[n][m];
        int[][] visited_f = new int[n][m]; 
        for(int i = 0; i < n; i++){
            Arrays.fill(visited_f[i], 987654321);
        }
        Queue<Pair> q = new ArrayDeque<>();
        for(Pair p : fire){
            q.offer(p);
            visited_f[p.y][p.x] = 1;
        }
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(visited_f[ny][nx] != 987654321 || map[ny][nx] == '#') continue;
                q.offer(new Pair(ny, nx));
                visited_f[ny][nx] = visited_f[y][x] + 1;
            }
        }
        q.offer(jihun);
        visited_j[jihun.y][jihun.x] = 1;
        while(!q.isEmpty()){
            Pair cur = q.poll();
            int y = cur.y;
            int x = cur.x;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m){
                    ret = visited_j[y][x] + 1;
                    break;
                }
                if(map[ny][nx] == '#' || visited_j[ny][nx] != 0 || visited_j[y][x] + 1 >= visited_f[ny][nx]) continue;
                q.offer(new Pair(ny, nx));
                visited_j[ny][nx] = visited_j[y][x] + 1;
            }
            if(ret != -1) break;
        }
        System.out.println(ret == -1 ? "IMPOSSIBLE" : ret - 1);
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
