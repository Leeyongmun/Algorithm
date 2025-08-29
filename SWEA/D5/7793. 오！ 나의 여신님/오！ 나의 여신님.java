import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    static int T, n, m;
    static char[][] map;
    static int[][] a;
    static Pair suyeon, god;
    static ArrayList<Pair> devil = new ArrayList<>();
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            map = new char[n][m];
            a = new int[n][m];
            devil.clear();
            for(int i = 0; i < n; i++){
                Arrays.fill(a[i], 987654321);
            }
            
            for(int i = 0; i < n; i++){
                String s = sc.next();
                for(int j = 0; j < m; j++){
                    map[i][j] = s.charAt(j);
                    if(map[i][j] == 'D'){
                        god = new Pair(i, j);
                    }
                    else if(map[i][j] == 'S'){
                        suyeon = new Pair(i, j);
                    }
                    else if(map[i][j] == '*'){
                        devil.add(new Pair(i, j));
                    }
                }
            }
            for(Pair p : devil){
                bfs(p);
            }
            int[][] visited = new int[n][m];
            Queue<Pair> q = new ArrayDeque<>();
            q.offer(suyeon);
            visited[suyeon.y][suyeon.x] = 1;
            while(!q.isEmpty()){
                Pair cur = q.poll();
                int y = cur.y;
                int x = cur.x;
                if(y == god.y && x == god.x){
                    break;
                }
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if(map[ny][nx] == 'X') continue;
                    if(visited[ny][nx] != 0) continue;
                    if(visited[y][x] + 1 < a[ny][nx]){
                        q.offer(new Pair(ny, nx));
                        visited[ny][nx] = visited[y][x] + 1;
                    }
                }
            }
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++){
            //         System.out.print(a[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            if(visited[god.y][god.x] != 0) System.out.println("#" + t + " " + (visited[god.y][god.x] - 1));
            else System.out.println("#" + t + " " + "GAME OVER");
        }
    }

    static void bfs(Pair p){
        int[][] visited = new int[n][m];
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(p);
        a[p.y][p.x] = 1;
        visited[p.y][p.x] = 1;
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
                if(visited[ny][nx] != 0) continue;
                if(visited[y][x] + 1 < a[ny][nx]){
                    a[ny][nx] = visited[y][x] + 1;
                    visited[ny][nx] = visited[y][x] + 1;
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
