import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int n, m, d;
    static int[][] a;
    static ArrayList<Integer> tmp = new ArrayList<>();
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        d = sc.nextInt();
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = sc.nextInt();
            }
        }
        solve(0);
        System.out.println(ret);
    }

    private static void solve(int now){
        if(tmp.size() == 3){
            int[][] b = new int[n][m];
            for(int i = 0; i < n; i++) b[i] = a[i].clone(); // 깊은복사
            int kill = 0;
            for(int round = 0; round < n; round++){
                Set<Pair> target = new HashSet<>();
                for(int ac : tmp){
                    Pair p = getTarget(b, ac);
                    if(p != null) target.add(p);
                }
                for(Pair p : target){
                    if(b[p.y][p.x] == 1){
                        b[p.y][p.x] = 0;
                        kill++;
                    }
                }
                for(int i = n - 1; i >= 1; i--){
                    b[i] = b[i - 1].clone();
                }
                Arrays.fill(b[0], 0);
            }
            ret = Math.max(ret, kill);
            return;
        }
        for(int i = now; i < m; i++){
            tmp.add(i);
            solve(i + 1);
            tmp.remove(tmp.size() - 1);
        }
    }

    private static Pair getTarget(int[][] b, int ac){
        int min = 987654321;
        int y = -1, x = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(b[i][j] == 0) continue;
                int dist = (n - i) + Math.abs(j - ac);
                if(dist > d) continue;
                if(dist < min){
                    min = dist;
                    y = i;
                    x = j;
                }else if(dist == min){
                    if(j < x){
                        y = i;
                        x = j;
                    }
                }
            }
        }
        return (y == -1) ? null : new Pair(y, x);
    }
}

class Pair{
    int y;
    int x;
    Pair(int y, int x){
        this.y = y;
        this.x = x;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj) return true;
        Pair p = (Pair) obj;
        return y == p.y && x == p.x;
    }

    @Override
    public int hashCode() {
        // TODO Auto-generated method stub
        return 31 * y + x;
    }
}