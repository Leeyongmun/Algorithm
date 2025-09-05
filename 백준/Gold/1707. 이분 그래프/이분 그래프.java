import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int k, n, m;
    static ArrayList<Integer>[] a;
    static int check[];
    static boolean flag = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        for(int t = 1; t <= k; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            a = new ArrayList[n + 1];
            check = new int[n + 1];
            flag = false;
            for(int i = 1; i <= n; i++){
                a[i] = new ArrayList<>();
            }
            for(int i = 0; i < m; i++){
                int from = sc.nextInt();
                int to = sc.nextInt();
                a[from].add(to);
                a[to].add(from);
            }
            for(int i = 1; i <= n; i++){
                if(flag) break;
                if(check[i] != 0) continue;
                dfs(i, 1);
            }
            System.out.println(flag ? "NO" : "YES");
        }
    }

    private static void dfs(int now, int type){
        check[now] = type;
        for(int next : a[now]){
            if(check[next] == 0){
                dfs(next, -type);
                if(flag) return;
            }
            else if(check[next] == type){
                flag = true;
                return;
            }
        }
    }
}
