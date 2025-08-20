import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, x, y, m;
    static ArrayList<Integer>[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++){
            a[i] = new ArrayList<>();
        }
        x = sc.nextInt();
        y = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            a[from].add(to);
            a[to].add(from);
        }
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(x);
        visited[x] = true;
        int cnt = 0;
        while(!q.isEmpty()){
            int size = q.size();
            cnt++;
            for(int i = 0; i < size; i++){
                int cur = q.poll();
                if(cur == y){
                    System.out.println(cnt - 1);
                    return;
                }
                for(int next : a[cur]){
                    if(visited[next]) continue;
                    q.offer(next);
                    visited[next] = true;
                }
            }
        }
        System.out.println(-1);
    }
}

