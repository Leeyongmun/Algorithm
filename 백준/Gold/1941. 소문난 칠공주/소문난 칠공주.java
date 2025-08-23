import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static char[][] a = new char[5][5];
    static ArrayList<Pair> v = new ArrayList<>();
    static int mask = 0;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 5; i++){
            String s = sc.next();
            for(int j = 0; j < 5; j++){
                a[i][j] = s.charAt(j);
                v.add(new Pair(i, j));
            }
        }
        solve(0, 0);
        System.out.println(ret);
    }

    private static void solve(int now, int cnt){
        if(cnt == 7){
            boolean[][] selected = new boolean[5][5];
            int S = 0;
            int Y = 0;
            Pair p = null;
            for(int i = 0; i < 25; i++){
                if((mask & (1 << i)) != 0){
                    p = v.get(i);
                    selected[p.y][p.x] = true;
                    if(a[p.y][p.x] == 'S') S++;
                    else Y++;
                }
            }
            if(Y > S) return;
            Queue<Pair> q = new ArrayDeque<>();
            q.offer(p);
            selected[p.y][p.x] = false;
            int count = 1;
            while(!q.isEmpty()){
                Pair tmp = q.poll();
                int y = tmp.y;
                int x = tmp.x;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
                    if(selected[ny][nx]){
                        count++;
                        q.offer(new Pair(ny, nx));
                        selected[ny][nx] = false;
                    }
                }
            }
            if(count == 7) ret++;
            return;
        }
        for(int i = now; i < 25; i++){
            mask |= (1 << i);
            solve(i + 1, cnt + 1);
            mask &= ~(1 << i);
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