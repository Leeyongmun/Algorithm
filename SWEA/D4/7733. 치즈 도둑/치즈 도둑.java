import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    static int T, n;
    static int[][] a;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            a = new int[n][n];
            visited = new boolean[n][n];
            int ret = 1;
            int max = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                    max = Math.max(max, a[i][j]);
                }
            }
            Queue<Pair> q = new ArrayDeque<>(100*100);
            for(int k = 1; k <= max; k++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(a[i][j] == k){
                            a[i][j] = 0;
                        }
                    }
                }
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        visited[i][j] = false;
                    }
                }
                int cnt = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(visited[i][j] || a[i][j] == 0) continue;
                        cnt++;
                        q.offer(new Pair(i, j));
                        visited[i][j] = true;
                        while(!q.isEmpty()){
                            Pair p = q.poll();
                            int y = p.y;
                            int x = p.x;
                            for(int dir = 0; dir < 4; dir++){
                                int ny = y + dy[dir];
                                int nx = x + dx[dir];
                                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                                if(visited[ny][nx]) continue;
                                if(a[ny][nx] == 0) continue;
                                q.offer(new Pair(ny, nx));
                                visited[ny][nx] = true;
                            }
                        }
                        ret = Math.max(cnt, ret);
                    }
                }
            }
            System.out.println("#" + t + " " + ret);
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
