import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m;
    static ArrayList<Integer>[] a;
    static boolean[] visited;
    static boolean flag = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new ArrayList[n];
        
        for(int i = 0; i < n; i++){
            a[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            a[from].add(to);
            a[to].add(from);
        }
        for(int i = 0; i < n; i++){
            visited = new boolean[n];
            visited[i] = true;
            dfs(i, 1);
            if(flag) break;
        }
        if(flag) System.out.println(1);
        else System.out.println(0);
    }

    private static void dfs(int cur, int cnt){
        if(cnt == 5){
            flag = true;
            return;
        }
        visited[cur] = true;
        for(int next : a[cur]){
            if(visited[next]) continue;
            dfs(next, cnt + 1);
        }
        visited[cur] = false;
    }
}
