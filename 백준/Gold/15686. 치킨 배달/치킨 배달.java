import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] a;
    static ArrayList<Pair> ch = new ArrayList<>();
    static ArrayList<Pair> home = new ArrayList<>();
    static ArrayList<Pair> tmp = new ArrayList<>();
    static boolean[] visited;
    static int ret = 987654321;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
                if(a[i][j] == 1){
                    home.add(new Pair(i, j));
                }
                else if(a[i][j] == 2){
                    ch.add(new Pair(i, j));
                }
            }
        }
        solve(0);
        System.out.println(ret);
    }

    private static void solve(int now){
        if(tmp.size() == m){
            int sum = 0;
            for(Pair h : home){
                int hy = h.y;
                int hx = h.x;
                int min_d = 987654321;
                for(Pair p : tmp){
                    int cy = p.y;
                    int cx = p.x;
                    int d = Math.abs(hy - cy) + Math.abs(hx - cx);
                    min_d = Math.min(min_d, d);
                }
                sum += min_d;
            }
            ret = Math.min(ret, sum);
        }
        for(int i = now; i < ch.size(); i++){
            tmp.add(ch.get(i));
            solve(i + 1);
            tmp.remove(tmp.size() - 1);
        }
    }
}

class Pair{
    int y, x;
    Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}
