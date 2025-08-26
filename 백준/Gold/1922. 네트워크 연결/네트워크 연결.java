import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static int n, m;
    static ArrayList<Edge> edge = new ArrayList<>();
    static int[] parent;

    static class Edge{
        int from, to, w;
        Edge(int from, int to, int w){
            this.from = from;
            this.to = to;
            this.w = w;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        parent = new int[n + 1];
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            int w = sc.nextInt();
            edge.add(new Edge(from, to, w));
        }

        edge.sort((a, b) -> {
            return a.w - b.w;
        });
        long ret = 0;
        int cnt = 0;
        for(Edge e : edge){
            if(!merge(e.from, e.to)) continue;
            ret += e.w;
            cnt++;
            if(cnt == n - 1) break;
        }
        System.out.println(ret);
    }

    private static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    private static boolean merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[x] = y;
        return true;
    }
}
