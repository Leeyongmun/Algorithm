import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
    static int T;
    static int n, m;
    static int[] parent;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            int ret = n;
            parent = new int[n + 1];
            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
            for(int i = 0; i < m; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                if(merge(x, y)) ret--;
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static int find(int x){
        if(x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }

    private static boolean merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[x] = y;
        return true;
    }
}
