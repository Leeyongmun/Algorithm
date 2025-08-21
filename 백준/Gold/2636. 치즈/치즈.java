import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] a;
    static int sum = 0;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
                if(a[i][j] == 1) sum++;
            }
        }
        int time = 0;
        while(true){
            time++;
            boolean[][] out = new boolean[n][m];
            Queue<Pair> q = new ArrayDeque<>();
            q.offer(new Pair(0, 0));
            out[0][0] = true;
            while(!q.isEmpty()){
                Pair cur = q.poll();
                int y = cur.y;
                int x = cur.x;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if(out[ny][nx]) continue;
                    if(a[ny][nx] == 0){
                        out[ny][nx] = true;
                        q.offer(new Pair(ny, nx));
                    }
                }
            }
            ArrayList<Pair> tmp = new ArrayList<>();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(a[i][j] == 1){
                        for(int dir = 0; dir < 4; dir++){
                            int ny = i + dy[dir];
                            int nx = j + dx[dir];
                            if(ny < 0 || nx < 0 || ny >= n || nx >= m || (a[ny][nx] == 0 && out[ny][nx])){
                                tmp.add(new Pair(i, j));
                                break;
                            }
                        }
                    }
                }
            }
            if(sum - tmp.size() == 0){
                break;
            }
            else sum -= tmp.size();
            for(Pair p : tmp){
                a[p.y][p.x] = 0;
            }
        }
        System.out.println(time);
        System.out.println(sum);
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